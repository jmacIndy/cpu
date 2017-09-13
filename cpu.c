#include "cpu.h"

void initializeCPU()
{
   register0 = 0x00;
   register1 = 0x00;
   flags = 0x00;
   programCounter = 0x00;
   heapPointer = 0x00;
}

void setGreaterThan()
{
   flags = flags | GREATERTHAN_SET;
}

void setLessThan()
{
   flags = flags | LESSTHAN_SET;
}

void setZero()
{
   flags = flags | ZERO_SET;
}

void setNonZero()
{
   flags = flags | NONZERO_SET;
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

void resetGreaterThan()
{
   flags = flags & GREATERTHAN_RESET;
}

void resetLessThan()
{
   flags = flags & LESSTHAN_RESET;
}

void resetZero()
{
   flags = flags & ZERO_RESET;
}

void resetNonZero()
{
   flags = flags & NONZERO_RESET;
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

int isGreaterThan()
{
   return flags & GREATERTHAN_SET;
}

int isLessThan()
{
   return flags & LESSTHAN_SET;
}

int isZero()
{
   return flags & ZERO_SET;
}

int isNonZero()
{
   return flags & NONZERO_SET;
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
   if (isGreaterThan())
   {
      printf("GreaterThan ");
   }
   if (isLessThan())
   {
      printf("LessThan ");
   }
   if (isZero())
   {
      printf("Zero ");
   }
   if (isNonZero())
   {
      printf("NonZero ");
   }
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

void pushCPUState() {

    push(register0);
    push(register1);
    push(programCounter);
    push(heapPointer);
    push(flags);
}

void popCPUState() {

    flags = pop();
    heapPointer = pop();
    programCounter = pop();
    register1 = pop();
    register0 = pop();
}
