#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

#define MAX_TOKEN_SIZE 20
#define MAX_LINE_SIZE 80
#define SYMBOL_TABLE_SIZE 100
#define MAX_FILENAME_SIZE 50

#define NUM_NOOP_KEYWORDS 12
#define NUM_OP_KEYWORDS 14
#define MAX_KEYWORD_SIZE 5

int inDataSection = 0;
int inConstantSection = 0;
int inCodeSection = 0;

enum symbolTypes
{
   constant,
   variable,
   label
};

struct symtab
{
   int id;
   char name[MAX_TOKEN_SIZE];
   int value;
   enum symbolTypes stype;
};

struct symtab symbolTable[SYMBOL_TABLE_SIZE];

int symbolCounter = 0;

int addressCount = 0;
int dataCount = 0;

char noOpKeywords[NUM_NOOP_KEYWORDS][MAX_KEYWORD_SIZE] =
{ "HALT", "ADD", "MULT", "DIV", "SUB", "RET", "INT", "CMP",
   "INC0", "INC1", "DEC0", "DEC1" };

char opKeywords[NUM_OP_KEYWORDS][MAX_KEYWORD_SIZE] = 
{ "SET0", "SET1", "STOR", "PRT",
  "JEQ", "JNE", "JLT", "JGT", "CALL", "JNZ", "JMP",
  "JZ", "LD0", "LD1" };

void printSymbols()
{
   printf("Symbol Table:\n");

   for (int i = 0; i < symbolCounter; i++)
   {
      printf("%2d %s %02X %d\n", symbolTable[i].id, symbolTable[i].name,
         symbolTable[i].value, symbolTable[i].stype);
   }
}

int isKeyword(char *token)
{
   for (int i = 0; i < NUM_NOOP_KEYWORDS; i++)
   {
      if ((strcmp(token, noOpKeywords[i])) == 0)
      {
         return 1;
      }
   }

   for (int i = 0; i < NUM_OP_KEYWORDS; i++)
   {
      if ((strcmp(token, opKeywords[i])) == 0)
      {
         return 2;
      }
   }

   return 0;
}

void pass1ProcessLine(char *token)
{
   if ((strcmp(token, "//")) == 0)
   {
      return;
   }
   else if ((strlen(token) > 1) && (token[0] == '/') && (token[1] == '/'))
   {
      return;
   }
   else if ((strcmp(token, ".CODE")) == 0)
   {
      inCodeSection = 1;
      inConstantSection = 0;
      inDataSection = 0;
   }
   else if ((strcmp(token, ".DATA")) == 0)
   {
      inDataSection = 1;
      inConstantSection = 0;
      inCodeSection = 0;
   }
   else if ((strcmp(token, ".CONSTANT")) == 0)
   {
      inConstantSection = 1;
      inDataSection = 0;
      inCodeSection = 0;
   }
   else if (inConstantSection)
   {
      symbolTable[symbolCounter].id = symbolCounter;
      strcpy(symbolTable[symbolCounter].name, token);
      symbolTable[symbolCounter].value =
         (int) strtol(strtok(NULL, " \t\n"), NULL, 0);
      symbolTable[symbolCounter].stype = constant;
      symbolCounter++;
   }
   else if (inDataSection)
   {
      symbolTable[symbolCounter].id = symbolCounter;
      strcpy(symbolTable[symbolCounter].name, token);
      symbolTable[symbolCounter].value = dataCount++;
      symbolTable[symbolCounter].stype = variable;
      symbolCounter++;
   }
   else if (inCodeSection)
   {
      int rc = isKeyword(token);
      if (rc == 0)
      {
         symbolTable[symbolCounter].id = symbolCounter;
         strcpy(symbolTable[symbolCounter].name, token);
         symbolTable[symbolCounter].value = addressCount;
         symbolTable[symbolCounter].stype = label;
         symbolCounter++;
         token = strtok(NULL, " \t\n");
         rc = isKeyword(token);
      }
      if (rc == 1)
      {
         addressCount++;
      }
      else
      {
         addressCount += 2;
      }
   }
   else
   {
      return;
   }
}

int findSymbol(char *token, enum symbolTypes stype)
{
   for (int i = 0; i < symbolCounter; i++)
   {
      if (((strcmp(token, symbolTable[i].name)) == 0) &&
            (symbolTable[i].stype == stype))
      {
         return symbolTable[i].value;
      }
   }

   return -1;
}

void pass2ProcessLine(char *token, FILE *outFile)
{
   // skip over comments
   if ((strcmp(token, "//")) == 0)
   {
      return;
   }
   else if ((strlen(token) > 1) && (token[0] == '/') && (token[1] == '/'))
   {
      return;
   }

   if ((strcmp(token, ".CODE")) == 0)
   {
      inCodeSection = 1;
      inConstantSection = 0;
      inDataSection = 0;
   }
   else if (inCodeSection)
   {
      // if this isn't a keyword, it's a label,  skip over it, 
      // and grab keyword - later, we'll have to fix this, because
      // we need to update symbol table to contain this address
      if (!isKeyword(token))
      {
         token = strtok(NULL, " \t\n");
      }

      if ((strcmp(token, "HALT")) == 0) // DONE
      {
         fprintf(outFile, "00");
      }
      else if ((strcmp(token, "SET0")) == 0) // op: literal or constant
      {
         fprintf(outFile, "01");
         token = strtok(NULL, " \t\n");
         int val = findSymbol(token, constant);
         if (val == -1)
         {
            fprintf(outFile, "%02X", (int) strtol(token, NULL, 0));
         }
         else
         {
            fprintf(outFile, "%02X", val);
         }
      }
      else if ((strcmp(token, "SET1")) == 0) // op: literal or constant
      {
         fprintf(outFile, "02");
         token = strtok(NULL, " \t\n");
         int val = findSymbol(token, constant);
         if (val == -1)
         {
            fprintf(outFile, "%02X", (int) strtol(token, NULL, 0));
         }
         else
         {
            fprintf(outFile, "%02X", val);
         }
      }
      else if ((strcmp(token, "ADD")) == 0) // DONE
      {
         fprintf(outFile, "03");
      }
      else if ((strcmp(token, "STOR")) == 0) // DONE
      {
         fprintf(outFile, "04");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, variable));
      }
      else if ((strcmp(token, "PRT")) == 0) // DONE
      {
         fprintf(outFile, "05");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, variable));
      }
      else if ((strcmp(token, "MULT")) == 0) // DONE
      {
         fprintf(outFile, "07");
      }
      else if ((strcmp(token, "DIV")) == 0) // DONE
      {
         fprintf(outFile, "08");
      }
      else if ((strcmp(token, "SUB")) == 0) // DONE
      {
         fprintf(outFile, "09");
      }
      else if ((strcmp(token, "JEQ")) == 0) // DONE
      {
         fprintf(outFile, "0A");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "JNE")) == 0) // DONE
      {
         fprintf(outFile, "0B");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "JLT")) == 0) // DONE
      {
         fprintf(outFile, "0C");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "JGT")) == 0) // DONE
      {
         fprintf(outFile, "0D");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "CALL")) == 0) // DONE
      {
         fprintf(outFile, "0E");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "RET")) == 0) // DONE
      {
         fprintf(outFile, "0F");
      }
      else if ((strcmp(token, "INT")) == 0) // DONE
      {
         fprintf(outFile, "10");
      }
      else if ((strcmp(token, "CMP")) == 0) // DONE
      {
         fprintf(outFile, "11");
      }
      else if ((strcmp(token, "JNZ")) == 0) // DONE
      {
         fprintf(outFile, "12");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "JMP")) == 0) // DONE
      {
         fprintf(outFile, "13");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "JZ")) == 0) // DONE
      {
         fprintf(outFile, "14");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, label));
      }
      else if ((strcmp(token, "INC0")) == 0) // DONE
      {
         fprintf(outFile, "15");
      }
      else if ((strcmp(token, "INC1")) == 0) // DONE
      {
         fprintf(outFile, "16");
      }
      else if ((strcmp(token, "DEC0")) == 0) // DONE
      {
         fprintf(outFile, "17");
      }
      else if ((strcmp(token, "DEC1")) == 0) // DONE
      {
         fprintf(outFile, "18");
      }
      else if ((strcmp(token, "LD0")) == 0) // DONE
      {
         fprintf(outFile, "19");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, variable));
      }
      else if ((strcmp(token, "LD1")) == 0) // DONE
      {
         fprintf(outFile, "1A");
         token = strtok(NULL, " \t\n");
         fprintf(outFile, "%02X", findSymbol(token, variable));
      }
      else
      {
         printf("ERROR: Bad instruction in CODE section!\n");
      }
   }
   else
   {
      return;
   }
}

int main(int argc, char *argv[])
{
   int ch;
   char *inputLine;
   size_t lineSize = MAX_LINE_SIZE;

   if (argc != 2)
   {
      printf("ERROR: Must provide file name on command line!\n");
      return -1;
   }

   FILE *inFile = fopen(argv[1], "r");
   if (inFile == 0)
   {
      printf("ERROR: Could not open file %s\n", argv[1]);
      return -1;
   }

   inputLine = (char *) malloc(lineSize + 1);

   while (getline(&inputLine, &lineSize, inFile) != -1)
   {
      if (strlen(inputLine) == 1)
      {
         continue;
      }

      char *token = strtok(inputLine, " \t\n");
      pass1ProcessLine(token);
   }

   /* printSymbols(); */

   rewind(inFile);

   inCodeSection = 0;
   inConstantSection = 0;
   inDataSection = 0;

   char *fileName = strtok(argv[1], ".");
   char outputFileName[MAX_FILENAME_SIZE];
   strcpy(outputFileName, fileName);
   strcat(outputFileName, ".cpu");
   FILE *outFile = fopen(outputFileName, "w");

   fprintf(outFile, "CPU");

   while (getline(&inputLine, &lineSize, inFile) != -1)
   {
      if (strlen(inputLine) == 1)
      {
         continue;
      }

      char *token = strtok(inputLine, " \t\n");
      pass2ProcessLine(token, outFile);
   }

   free(inputLine);

   fclose(outFile);
   fclose(inFile);

   return 0;
}
