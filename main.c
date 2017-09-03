#include <stdio.h>

#include "cpu.h"
#include "memory.h"
#include "heap.h"
#include "stack.h"
#include "ops.h"

void loadDefaultProgram()
{
   writeMemory(0x00, 0x01); // LDR0 0x02
   writeMemory(0x01, 0x02);
   writeMemory(0x02, 0x02); // LDR1 0x07
   writeMemory(0x03, 0x07);
   writeMemory(0x04, 0x03); // ADD
   writeMemory(0x05, 0x04); // STOR 0x00
   writeMemory(0x06, 0x00);
   writeMemory(0x07, 0x05); // PRT 0x00
   writeMemory(0x08, 0x00);
   writeMemory(0x09, 0x0E); // CALL 0x0D
   writeMemory(0x0A, 0x0D);
   writeMemory(0x0B, 0x06); // BEEP
   writeMemory(0x0C, 0x00); // HALT
   writeMemory(0x0D, 0x01); // LDR0 0x04
   writeMemory(0x0E, 0x04);
   writeMemory(0x0F, 0x02); // LDR1 0x09
   writeMemory(0x10, 0x09);
   writeMemory(0x11, 0x03); // ADD
   writeMemory(0x12, 0x04); // STOR 0x01
   writeMemory(0x13, 0x01);
   writeMemory(0x14, 0x05); // PRT 0x01
   writeMemory(0x15, 0x01);
   writeMemory(0x16, 0x01); // LDR0 0x0A
   writeMemory(0x17, 0x0A);
   writeMemory(0x18, 0x04); // STORE 0x02
   writeMemory(0x19, 0x02);
   writeMemory(0x1A, 0x05); // PRT 0x02
   writeMemory(0x1B, 0x02);
   writeMemory(0x1C, 0x17); // DEC0
   writeMemory(0x1D, 0x12); // JNZ 0x18
   writeMemory(0x1E, 0x18);
   writeMemory(0x1F, 0x0F); // RET
}

int displayMenu()
{
   int choice;

   printf("Menu (my CPU)\n");
   printf("-------------\n");
   printf("1. Load Default Program\n");
   printf("2. Reset CPU\n");
   printf("3. Clear Memory\n");
   printf("4. Dump the CPU\n");
   printf("5. Dump the Memory\n");
   printf("6. Dump the Heap\n");
   printf("7. Dump the Stack\n");
   printf("8. Run the CPU\n");
   printf("9. Compile/Load Program\n");
   printf("X. Exit the CPU\n");
   printf("   Your choice===>");

   choice = getchar();
   getchar(); /* consume the newline */

   return choice;
}

int main()
{
   int menuChoice;

   int exitFlag = 0;

   clearMemory();
   clearHeap();
   initializeCPU();
   clearStack();

   printf("=======================\n");
   printf("== Welcome to my CPU ==\n");
   printf("=======================\n\n");

   while (!exitFlag)
   {
      menuChoice = displayMenu();

      switch (menuChoice)
      {
      case '1':
         loadDefaultProgram();
         break;
      case '2':
         initializeCPU();
         break;
      case '3':
         clearMemory();
         break;
      case '4':
         dumpCPU();
         break;
      case '5':
         dumpMemory();
         break;
      case '6':
         dumpHeap();
         break;
      case '7':
         dumpStack();
         break;
      case '8':
         if (isHalt())
         {
            printf("ERROR: CPU is HALTED! Cannot run!\n");
         }
         else
         {
            run();
         }
         break;
      case '9':
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

   return 0;
}
