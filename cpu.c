#include "cpu.h"

void initializeCPU()
{
   register0 = 0x00;
   register1 = 0x00;
   flags = 0x00;
   programCounter = 0x00;
   heapPointer = 0x00;
}

void setOverflow()
{
   flags = flags | OVERFLOW_SET;
}

void setUnderflow()
{
   flags = flags | UNDERFLOW_SET;
}

void setSigning()
{
   flags = flags | SIGNING_SET;
}

void setHalt()
{
   flags = flags | HALT_SET;
}

void resetOverflow()
{
   flags = flags & OVERFLOW_RESET;
}

void resetUnderflow()
{
   flags = flags & UNDERFLOW_RESET;
}

void resetSigning()
{
   flags = flags & SIGNING_RESET;
}

void resetHalt()
{
   flags = flags & HALT_RESET;
}

int isOverflow()
{
   return flags & OVERFLOW_SET;
}

int isUnderflow()
{
   return flags & UNDERFLOW_SET;
}

int isSigning()
{
   return flags & SIGNING_SET;
}

int isHalt()
{
   return flags & HALT_SET;
}

void printRegister0()
{
   printf("Register 0      : %02X\n", register0);
}

void printRegister1()
{
   printf("Register 1      : %02X\n", register1);
}

void printProgramCounter()
{
   printf("Program Counter : %02X\n", programCounter);
}

void printHeapPointer()
{
   printf("Heap Pointer    : %02X\n", heapPointer);
}

void printFlags()
{
   printf("Flags           : ");
   if (isOverflow())
   {
      printf("Overflow ");
   }
   if (isUnderflow())
   {
      printf("Underflow ");
   }
   if (isSigning())
   {
      printf("Signing ");
   }
   if (isHalt())
   {
      printf("Halt");
   }

   printf("\n");
}

void dumpCPU()
{
   printf("\nCPU Contents:\n");
   printf("-------------\n");

   printRegister0();
   printRegister1();
   printProgramCounter();
   printHeapPointer();
   printFlags();
   printf("\n");
}
