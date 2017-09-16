#include <iostream>

#include "Cpu.h"
#include "Memory.h"
#include "Heap.h"
#include "Stack.h"
#include "Bios.h"

/*
#define MAX_FILENAME_SIZE 50
#define MAX_INPUT_SIZE 500

int displayMenu()
{
   int choice;

   printf("Menu (my CPU)\n");
   printf("-------------\n");
   printf("1. Reset CPU\n");
   printf("2. Clear Memory\n");
   printf("3. Dump the CPU\n");
   printf("4. Dump the Memory\n");
   printf("5. Dump the Heap\n");
   printf("6. Dump the Stack\n");
   printf("7. Run the CPU\n");
   printf("8. Load program from file\n");
   printf("X. Exit the CPU\n");
   printf("   Your choice===>");

   choice = getchar();
   getchar();  // consume the newline
   return choice;
}

void loadProgram()
{
   char inName[MAX_FILENAME_SIZE];

   printf("\nEnter input file name ===> ");
   fgets(inName, sizeof(inName), stdin);
   inName[strlen(inName) - 1] = '\0'; // remove training \n

   FILE *inFile = fopen(inName, "r");
   if (inFile == 0)
   {
      printf("ERROR: Could not open file %s\n", inName);
      return;
   }

   char *inputLine;
   size_t lineSize = MAX_INPUT_SIZE;

   inputLine = (char *) malloc(lineSize + 1);

   if (getline(&inputLine, &lineSize, inFile) == -1)
   {
      printf("ERROR: File is empty. Nothing to load.\n");
      return;
   }

   int filePointer = 3; // skip over CPU text
   byte memoryPointer = 0x00;
   for (int i = filePointer; i < strlen(inputLine); i += 2)
   {
      char inData[5];
      strcpy(inData, "0x");
      strncat(inData, inputLine + i, 2);
      writeMemory(memoryPointer, (int) strtol(inData, NULL, 0));
      memoryPointer++;
   }

   free(inputLine);

   fclose(inFile);
}

*/

int main()
{
   int menuChoice;

   int exitFlag = 0;

   Cpu cpu;
   Memory memory;
   Stack stack;
   Heap heap;
   Bios bios;

   std::cout << "========================="
             << std::endl
             << "=== Welcome to MY CPU ==="
             << std::endl
             << "========================="
             << std::endl
             << std::endl;

/*
   while (!exitFlag)
   {
      menuChoice = displayMenu();

      switch (menuChoice)
      {
      case '1':
         initializeCPU();
         break;
      case '2':
         clearMemory();
         break;
      case '3':
         dumpCPU();
         break;
      case '4':
         dumpMemory();
         break;
      case '5':
         dumpHeap();
         break;
      case '6':
         dumpStack();
         break;
      case '7':
         if (isHalt())
         {
            printf("ERROR: CPU is HALTED! Cannot run!\n");
         }
         else
         {
            run();
         }
         break;
      case '8':
         loadProgram();
         break;
      case 'X':
      case 'x':
         exitFlag = 1;
         break;
      default:
         printf("ERROR: Bad selection! Try again.\n");
         break;
      }
   }

*/

   return 0;
}
