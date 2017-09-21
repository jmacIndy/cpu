#include <iostream>
#include <fstream>
#include <string>

#include "Cpu.h"
#include "Memory.h"
#include "Heap.h"
#include "Stack.h"
#include "Ops.h"

typedef unsigned char byte;

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
   std::cin >> inName;

   std::ifstream inFile(inName);
   std::string inputLine((std::istreambuf_iterator<char>(inFile)),
      (std::istreambuf_iterator<char>() ));

   int filePointer = 3; // skip over CPU text
   byte memoryPointer = 0x00;
   for (std::string::size_type i = filePointer; i < inputLine.size(); i += 2)
   {
      std::string inData = "0x";
      inData.push_back(inputLine[i]);
      inData.push_back(inputLine[i+1]);
      memory.write(memoryPointer, std::stoul(inData, nullptr, 16));
      memoryPointer++;
   }
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
