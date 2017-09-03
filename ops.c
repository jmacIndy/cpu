#include "ops.h"

/* FUNCTION: opHalt (HALT op code 0x00) */
void opHalt()
{
   setHalt();
   programCounter++;
}

/* FUNCTION: opLoad0 (LDR0 op code 0x01) */
void opLoad0()
{
   programCounter++;
   register0 = readMemory(programCounter);
   programCounter++;
}

/* FUNCTION: opLoad1 (LDR1 op code 0x02) */
void opLoad1()
{
   programCounter++;
   register1 = readMemory(programCounter);
   programCounter++;
}

/* FUNCTION: opAdd (ADD op code 0x03) */
void opAdd()
{
   register0 += register1;
   programCounter++;
}

/* FUNCTION: opStore (STOR op code 0x04) */
void opStore()
{
   programCounter++;
   heapPointer = readMemory(programCounter);
   writeHeap(heapPointer, register0);
   programCounter++;
}

/* FUNCTION: opPrint (PRT op code 0x05) */
void opPrint()
{
   programCounter++;
   heapPointer = readMemory(programCounter);
   printf("HEAP ADDRESS: %02X VALUE: %02X\n", heapPointer, 
      readHeap(heapPointer));
   programCounter++;
}

/* FUNCTION opBeep (BEEP op code 0x06) */
void opBeep()
{
   printf("BEEP!\n");
   programCounter++;
}

/* FUNCTION: opMultiply (MULT op code 0x07) */
void opMultiply()
{
   register0 *= register1;
   programCounter++;
}

/* FUNCTION; opDivide (DIV op code 0x08) */
void opDivide()
{
   register0 = register0 / register1;
   programCounter++;
}

/* FUNCTION: opSubtract (SUB op code 0x09) */
void opSubtract()
{
   register0 = register0 - register1;
   programCounter++;
}

/* FUNCTION: opJumpEqual (JEQ op code 0x0A) */
void opJumpEqual()
{
   programCounter++;
   if (register0 == register1)
   {
      programCounter = readMemory(programCounter);
   }
   else
   {
      programCounter++;
   }
}

/* FUNCTION: opJumpNotEqual (JNE op code 0x0B) */
void opJumpNotEqual()
{
   programCounter++;
   if (register0 != register1)
   {
      programCounter = readMemory(programCounter);
   }
   else
   {
      programCounter++;
   }
}

/* FUNCTION: opJumpLessThan (JLT op code 0x0C) */
void opJumpLessThan()
{
   programCounter++;
   if (register0 < register1)
   {
      programCounter = readMemory(programCounter);
   }
   else
   {
      programCounter++;
   }
}

/* FUNCTION: opJumpGreaterThan (JGT op code 0x0D) */
void opJumpGreaterThan()
{
   programCounter++;
   if (register0 > register1)
   {
      programCounter = readMemory(programCounter);
   }
   else
   {
      programCounter++;
   }
}

/* FUNCTION: opCall (CALL op code 0x0E) */
void opCall()
{
   programCounter++;
   push(programCounter + 1);
   programCounter = readMemory(programCounter);
}

/* FUNCTION: opReturn (RET op code 0x0F) */
void opReturn()
{
   programCounter = pop();
}

/* FUNCTION: opInterrupt (INT op code 0x10) */
void opInterrupt()
{
   ; // TODO
}

/* FUNCTION: opCompare (CMP op code 0x11) */
void opCompare()
{
   ; // TODO
}

/* FUNCTION: opJumpNotZero (JNZ op code 0x12) */
void opJumpNotZero()
{
   programCounter++;
   if (register0 != 0)
   {
      programCounter = readMemory(programCounter);
   }
   else
   {
      programCounter++;
   }
}

/* FUNCTION: opJump (JMP op code 0x13) */
void opJump()
{
   programCounter++;
   programCounter = readMemory(programCounter);
}

/* FUNCTION: opJumpZero (JZ opcode 0x14) */
void opJumpZero()
{
   programCounter++;
   if (register0 == 0)
   {
      programCounter = readMemory(programCounter);
   }
   else
   {
      programCounter++;
   }
}

/* FUNCTION: opIncrement0 (INC0 opcode 0x15) */
void opIncrement0()
{
   register0++;
   programCounter++;
}

/* FUNCTION: opIncrement1 (INC1 opcode 0x16) */
void opIncrement1()
{
   register1++;
   programCounter++;
}

/* FUNCTION; opDecrement0 (DEC0 opcode 0x17) */
void opDecrement0()
{
   register0--;
   programCounter++;
}

/* FUNCTION: opDecrement1 (DEC1 opcode 0x18) */
void opDecrement1()
{
   register1--;
   programCounter++;
}

/* FUNCTION: run */
void run()
{
   printf("... Running ...\n");

   while (1)
   {
      switch(readMemory(programCounter))
      {
      case 0x00:
         opHalt();
         break;
      case 0x01:
         opLoad0();
         break;
      case 0x02:
         opLoad1();
         break;
      case 0x03:
         opAdd();
         break;
      case 0x04:
         opStore();
         break;
      case 0x05:
         opPrint();
         break;
      case 0x06:
         opBeep();
         break;
      case 0x07:
         opMultiply();
         break;
      case 0x08:
         opDivide();
         break;
      case 0x09:
         opSubtract();
         break;
      case 0x0A:
         opJumpEqual();
         break;
      case 0x0B:
         opJumpNotEqual();
         break;
      case 0x0C:
         opJumpLessThan();
         break;
      case 0x0D:
         opJumpGreaterThan();
         break;
      case 0x0E:
         opCall();
         break;
      case 0x0F:
         opReturn();
         break;
      case 0x10:
         opInterrupt();
         break;
      case 0x11:
         opCompare();
         break;
      case 0x12:
         opJumpNotZero();
         break;
      case 0x13:
         opJump();
         break;
      case 0x14:
         opJumpZero();
         break;
      case 0x15:
         opIncrement0();
         break;
      case 0x16:
         opIncrement1();
         break;
      case 0x17:
         opDecrement0();
         break;
      case 0x18:
         opDecrement1();
         break;
      default:
         printf("ERROR: Bad OpCode\n");
         break;
      }

      if (isHalt())
      {
         break;
      }
   }
}
