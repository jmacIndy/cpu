#include <iostream>
#include <string.h>

#include "Cpu.h"
#include "Memory.h"
#include "Heap.h"
#include "Stack.h"
#include "Ops.h"

#define MAX_FILENAME_SIZE 50
#define MAX_INPUT_SIZE 500

char displayMenu()
{
   char choice;

   std::cout << "Menu (my CPU)"
             << std::endl;
   std::cout << "-------------"
             << std::endl;
   std::cout << "1. Reset CPU"
             << std::endl;
   std::cout << "2. Clear Memory"
             << std::endl;
   std::cout << "3. Dump the CPU"
             << std::endl;
   std::cout << "4. Dump the Memory"
             << std::endl;
   std::cout << "5. Dump the Heap"
             << std::endl;
   std::cout << "6. Dump the Stack"
             << std::endl;
   std::cout << "7. Run the CPU"
             << std::endl;
   std::cout << "8. Load program from file"
             << std::endl;
   std::cout << "X. eXit the CPU"
             << std::endl;
   std::cout << "   Your choice===> ";

   std::cin >> choice;

   return choice;
}

void loadProgram(Memory &memory)
{
   char inName[MAX_FILENAME_SIZE];

   std::cout << std::endl
             << "Enter input file name ===> ";
   fgets(inName, sizeof(inName), stdin);
   inName[strlen(inName) - 1] = '\0'; // remove trailing \n

   FILE *inFile = fopen(inName, "r");
   if (inFile == 0)
   {
      std::cout << "ERROR: Could not open file "
                << inName
                << std::endl;
      return;
   }

   char *inputLine;
   size_t lineSize = MAX_INPUT_SIZE;

   inputLine = (char *) malloc(lineSize + 1);

   if (getline(&inputLine, &lineSize, inFile) == -1)
   {
      std::cout << "ERROR: File is empty. Nothing to load."
                << std::endl;
      return;
   }

   int filePointer = 3; // skip over CPU text
   byte memoryPointer = 0x00;
   for (int i = filePointer; i < strlen(inputLine); i += 2)
   {
      char inData[5];
      strcpy(inData, "0x");
      strncat(inData, inputLine + i, 2);
      memory.write(memoryPointer, (int) strtol(inData, NULL, 0));
      memoryPointer++;
   }

   free(inputLine);

   fclose(inFile);
}

int main()
{
   Cpu cpu;
   Memory memory;
   Stack stack;
   Heap heap;

   bool exitFlag = false;

   std::cout << "========================="
             << std::endl
             << "=== Welcome to MY CPU ==="
             << std::endl
             << "========================="
             << std::endl
             << std::endl;

   while (!exitFlag)
   {
      switch (displayMenu())
      {
      case '1':
         cpu.initialize();
         break;
      case '2':
         memory.initialize();
         break;
      case '3':
         cpu.dump();
         break;
      case '4':
         memory.dump();
         break;
      case '5':
         heap.dump();
         break;
      case '6':
         stack.dump();
         break;
      case '7':
         if (cpu.isHalt())
         {
            std::cout << "ERROR: CPU is HALTED! Cannot run!"
                      << std::endl;
         }
         else
         {
            run(cpu, memory, heap, stack);
         }
         break;
      case '8':
         loadProgram(memory);
         break;
      case 'X':
      case 'x':
         exitFlag = true;
         break;
      default:
         std::cout << "ERROR: Bad selection! Try again!"
                   << std::endl;
         break;
      }
   }

   return 0;
}
