#include "Cpu.h"

// FUNCTION: initialize
// PURPOSE: Initialize CPU attributes to appropriate starting values
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: 
//    - Register 0 and Register 1 set to 0
//    - All flags turned off
//    - Program Counter and Head Pointer set to address 0

void Cpu::initialize() 
{
   setRegister0(0);
   setRegister1(0);
   resetOverflow();
   resetUnderflow();
   resetSigning();
   resetHalt();
   setProgramCounter(0);
   setHeapPointer(0);
}

// FUNCTION: printRegister0
// PURPOSE: Print contents of register 0
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Cpu::printRegister0() const
{
   std::cout << "Register 0      : " 
             << static_cast<int>(getRegister0())
             << std::endl;
}

// FUNCTION: printRegister1
// PURPOSE: Print contents of register 1
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Cpu::printRegister1() const
{
   std::cout << "Register 1      : " 
             << static_cast<int>(getRegister1())
             << std::endl;
}

// FUNCTION: printProgramCounter
// PURPOSE: Print contents of the program counter
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Cpu::printProgramCounter() const
{
   std::cout << "Program Counter : " 
             << static_cast<int>(getProgramCounter())
             << std::endl;
}

// FUNCTION: printHeapPointer
// PURPOSE: Print contents of the heap pointer
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Cpu::printHeapPointer() const
{
   std::cout << "Heap Pointer    : " 
             << static_cast<int>(getHeapPointer())
             << std::endl;
}

// FUNCTION: printFlags
// PURPOSE: Print flags that are ON
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Cpu::printFlags() const
{
   std::cout << "Flags           : ";
   if (isOverflow())
   {
      std::cout << "Overflow ";
   }
   if (isUnderflow())
   {
      std::cout << "Underflow ";
   }
   if (isSigning())
   {
      std::cout << "Signing ";
   }
   if (isHalt())
   {
      std::cout << "Halt";
   }

   std::cout << std::endl;
}

// FUNCTION: dump
// PURPOSE: Print out the contents of the CPU
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Cpu::dump() const
{
   std::cout << "CPU Contents:" 
             << std::endl;
   std::cout << "-------------" 
             << std::endl;

   std::cout << std::hex
             << std::setfill('0')
             << std::setw(2)
             << std::uppercase;

   printRegister0();
   printRegister1();
   printProgramCounter();
   printHeapPointer();
   printFlags();

   std::cout << std::setfill(' ');
}

// FUNCTION: opHalt (HALT op code 0x00)
// PURPOSE: Sets the halt flag.
// RETURNS: void
// ARGUMENTS: none
// SETUP: none
// EFFECTS: 
//    - Program Counter is incremented by 1

void Cpu::opHalt()
{
   setHalt();
   incrementProgramCounter();
}

// FUNCTION: opLoad0 (LDR0 op code 0x01)
// PURPOSE: Set value in Register 0
// RETURNS: void
// ARGUMENTS: 
//    - Reference to Memory object
// SETUP:
//    - operand specified as value to place in Register 0
// EFFECTS: 
//    - Register 0 has changed
//    - Program Counter incremented by 2

void Cpu::opLoad0(Memory& memory)
{
   incrementProgramCounter();
   setRegister0(memory.read(getProgramCounter()));
   incrementProgramCounter();
}

// FUNCTION: opLoad1 (LDR1 op code 0x02)
// PURPOSE: Set value in Register 1
// RETURNS: void
// ARGUMENTS: 
//    - Reference to Memory object
// SETUP: 
//    - operand specified as value to place in Register 1
// EFFECTS: 
//    - Register 1 has changed
//    - Program Counter incremented by 2

void Cpu::opLoad1(Memory& memory)
{
   incrementProgramCounter();
   setRegister1(memory.read(getProgramCounter()));
   incrementProgramCounter();
}

// FUNCTION: opAdd (ADD op code 0x03)
// PURPOSE: Add contents of Register 0 and Register 1 together
// RETURNS: void
// ARGUMENTS: none
// SETUP:
//    - Register 0 should contain a number to be added
//    - Register 1 should contain another number to be added
// EFFECTS: 
//    - Register 0 has changed
//    - Program Counter incremented by 1

void Cpu::opAdd()
{
   setRegister0(getRegister0() + getRegister1());
   incrementProgramCounter();
}

// FUNCTION: opStore (STOR op code 0x04)
// PURPOSE: Stores a value onto heap
// RETURNS: void
// ARGUMENTS:
//    - 1. Reference to Memory object
//    - 2. Reference to Heap object
// SETUP: 
//    - Register 0 must contain value to be written to heap
//    - Operand must contain heap address
// EFFECTS: 
//    - Value written onto heap
//    - Heap Pointer set to address of value written to heap
//    - Program Counter incrememted by 2

void Cpu::opStore(Memory& memory, Heap& heap)
{
   incrementProgramCounter();
   setHeapPointer(memory.read(getProgramCounter()));
   heap.write(getHeapPointer(), getRegister0());
   incrementProgramCounter();
}

// FUNCTION: opPrint (PRT op code 0x05)
// PURPOSE: Prints out a value from heap
// RETURNS: void
// ARGUMENTS: 
//    - 1. Reference to Memory object
//    - 2. Reference to Heap object
//    - Operand must contain heap address
// SETUP: none
// EFFECTS:
//    - Register 0 has been altered
//    - Program Counter incremented by 2

void Cpu::opPrint(Memory& memory, Heap& heap)
{
   incrementProgramCounter();
   setHeapPointer(memory.read(getProgramCounter()));
   std::cout << "HEAP ADDRESS: " 
             << static_cast<int>(getHeapPointer())
             << " VALUE: "
             << static_cast<int>(heap.read(getHeapPointer()))
             << std::endl;
   incrementProgramCounter();
}

// FUNCTION opBeep (BEEP op code 0x06)
// PURPOSE: Prints beep
// RETURNS: void
// ARGUMENTS: none
// EFFECTS:
//    - Program Counter incremented by 1

void Cpu::opBeep()
{
   std::cout << "BEEP!" 
             << std::endl;
   incrementProgramCounter();
}

// FUNCTION: opMultiply (MULT op code 0x07)
// PURPOSE: Multiples register 0 by register 1
// RETURNS: void
// ARGUMENTS:
//    - Register 0 should have first operand
//    - Register 1 should have second operand
// EFFECTS:
//    - Register 0 is modified (contains result of multiplication)
//    - Program Counter is incremented by 1

void Cpu::opMultiply()
{
   setRegister0(getRegister0() * getRegister1());
   incrementProgramCounter();
}

// FUNCTION; opDivide (DIV op code 0x08)
// PURPOSE: Divides register 0 by register 1
// RETURNS: void
// ARGUMENTS:
//    - Register 0 should contain first operand
//    - Register 1 should contain second operand
// EFFECTS:
//    - Register 0 is modified (contains result of division)
//    - Program Counter is incremented by 1

void Cpu::opDivide()
{
   setRegister0(getRegister0() / getRegister1());
   incrementProgramCounter();
}

// FUNCTION: opSubtract (SUB op code 0x09)
// PURPOSE: Subtracts register 1 from register 0
// RETURNS: void
// ARGUMENTS:
//    - Register 0 should contain first operand
//    - Register 1 should contain second operand
// EFFECTS:
//    - Register 0 is modified (contains result of subtraction)
//    - Program Counter is incremented by 1

void Cpu::opSubtract()
{
   setRegister0(getRegister0() - getRegister1());
   incrementProgramCounter();
}

// FUNCTION: opJumpEqual (JEQ op code 0x0A)
// PURPOSE: Jump to another location if Register 0 equals Register 1
// RETURNS: void
// ARGUMENTS:
//    1. Reference to memory address
// SETUP:
//    - register 0 should contain first operand to compare
//    - register 1 should contain second operand to compare
// EFFECTS:
//    - If registers equal, program counter set to address in operand
//    - Else, program counter incremented by 2

void Cpu::opJumpEqual(Memory& memory)
{
   incrementProgramCounter();
   if (getRegister0() == getRegister1())
   {
      setProgramCounter(memory.read(getProgramCounter()));
   }
   else
   {
      incrementProgramCounter();
   }
}

// FUNCTION: opJumpNotEqual (JNE op code 0x0B)
// PURPOSE: Jump to another location if register 0 and register 1 not equal
// RETURNS: void
// ARGUMENTS:
//    1. Reference to Memory object
// SETUP:
//    - Register 0 should contain first value to compare
//    - Register 1 should contain second value to compare
// EFFECTS:
//    - If register 0 and register 1 are not equal, program counter set
//      to address in operand
//    - Else, program counter is incremented by 2

void Cpu::opJumpNotEqual(Memory& memory)
{
   incrementProgramCounter();
   if (getRegister0() != getRegister1())
   {
      setProgramCounter(memory.read(getProgramCounter()));
   }
   else
   {
      incrementProgramCounter();
   }
}

// FUNCTION: opJumpLessThan (JLT op code 0x0C)
// PURPOSE: Jump to another location if register 0 is less than register 1
// RETURNS: void
// ARGUMENTS:
//    1. Reference to Memory object
// SETUP:
//    - Register 0 should be set to first value to compare
//    - Register 1 should be set to second value to compare
// EFFECTS:
//    - If Register 0 is less than Register 1, the program counter is set
//      to address in operand
//    - Else, the Program Counter is incremented by 2

void Cpu::opJumpLessThan(Memory& memory)
{
   incrementProgramCounter();
   if (getRegister0() < getRegister1())
   {
      setProgramCounter(memory.read(getProgramCounter()));
   }
   else
   {
      incrementProgramCounter();
   }
}

// FUNCTION: opJumpGreaterThan (JGT op code 0x0D)
// PURPOSE: Jump to another location if Register 0 is greater than Register 1
// RETURNS: void
// ARGUMENTS:
//    1. Reference to Memory object
// SETUP:
//    - Register 0 should contain first value to be compared
//    - Register 1 should contain second value to be compared
// EFFECTS:
//    - If Register 0 is greater than Register 1, set Program Counter to the
//      address in operand
//    - Else, increment Program Counter by 2

void Cpu::opJumpGreaterThan(Memory& memory)
{
   incrementProgramCounter();
   if (getRegister0() > getRegister1())
   {
      setProgramCounter(memory.read(getProgramCounter()));
   }
   else
   {
      incrementProgramCounter();
   }
}

// FUNCTION: opCall (CALL op code 0x0E)
// PURPOSE: Jump to a subroutine
// RETURNS: void
// ARGUMENTS: 
//    - Pass reference to Memory object
//    - operand contains starting address of subroutine
// EFFECTS:
//    - Item pushed onto stack
//    - Program Counter set to start of subroutine

void Cpu::opCall(Memory& memory)
{
   incrementProgramCounter();
   stack.push(getProgramCounter() + 1);
   setProgramCounter(memory.read(getProgramCounter()));
}

// FUNCTION: opReturn (RET op code 0x0F)
// PURPOSE: Return from a subroutine
// RETURNS: void
// ARGUMENTS: none
// EFFECTS:
//    - Item removed from stack
//    - Program Counter set to location after CALL statement

void Cpu::opReturn()
{
   setProgramCounter(stack.top());
   stack.pop();
}

// FUNCTION: opInterrupt (INT op code 0x10)

void Cpu::opInterrupt()
{
   // TODO
}

// FUNCTION: opCompare (CMP op code 0x11)

void Cpu::opCompare()
{
   // TODO
}

// FUNCTION: opJumpNotZero (JNZ op code 0x12)
// PURPOSE: Jump to another location if Register 0 not equal to zero
// RETURNS: void
// ARGUMENTS: 
//    1. Reference to Memory object
// SETUP:
//    - Register 0 should contain value to compare to zero
// EFFECTS:
//    - If Register 0 is equal to zero, set Program Counter equal to address
//      in operand
//    - Else, Program Counter is incremented by 2

void Cpu::opJumpNotZero(Memory& memory)
{
   incrementProgramCounter();
   if (getRegister0() != 0)
   {
      setProgramCounter(memory.read(getProgramCounter()));
   }
   else
   {
      incrementProgramCounter();
   }
}

// FUNCTION: opJump (JMP op code 0x13)
// PURPOSE: Jump to a new location, with no intention of returning
// RETURNS: void
// ARGUMENTS:
//    - Pass reference to Memory object
//    - operand contains address to jump to
// EFFECTS:
//    - Program Counter set to address in operand

void Cpu::opJump(Memory& memory)
{
   incrementProgramCounter();
   setProgramCounter(memory.read(getProgramCounter()));
}

// FUNCTION: opJumpZero (JZ opcode 0x14)
// PURPOSE: Jump to another location if Register 0 equals zero
// RETURNS: void
// ARGUMENTS:
//    1. Reference to Memory object
// SETUP:
//    - Register 0 should contain value to compare to zero
// EFFECTS:
//    - If Register 0 is equal to zero, set Program Counter equal to address
//      in operand
//    - Else, the Program Counter is incremented by 2

void Cpu::opJumpZero(Memory& memory)
{
   incrementProgramCounter();
   if (getRegister0() == 0)
   {
      setProgramCounter(memory.read(getProgramCounter()));
   }
   else
   {
      incrementProgramCounter();
   }
}

// FUNCTION: opIncrement0 (INC0 opcode 0x15)
// PURPOSE: Increment register 0 by 1
// RETURNS: void
// ARGUMENTS:
//    (none, except R0 should have value you wish to increment)
// EFFECTS:
//    Register 0 has been incremented by 1
//    Program Counter incremented by 1

void Cpu::opIncrement0()
{
   setRegister0(getRegister0() + 1);
   incrementProgramCounter();
}

// FUNCTION: opIncrement1 (INC1 opcode 0x16)
// PURPOSE: Increment Register 1 by 1
// RETURNS: void
// ARGUMENTS:
//    (none, except R1 should have value you wish to increment)
// EFFECTS:
//    - Register 1 has been incremented by 1
//    - Program Counter has been incremented by 1

void Cpu::opIncrement1()
{
   setRegister1(getRegister1() + 1);
   incrementProgramCounter();
}

// FUNCTION; opDecrement0 (DEC0 opcode 0x17)
// PURPOSE: Decrement register 0 by 1
// RETURNS: void
// ARGUMENTS:
//    - none, except R0 should have value you wish to decrement
// EFFECTS:
//    - Register 0 has been decremented by 1
//    - Program Counter has been incremented by 1

void Cpu::opDecrement0()
{
   setRegister0(getRegister0() - 1 );
   incrementProgramCounter();
}

// FUNCTION: opDecrement1 (DEC1 opcode 0x18)
// PURPOSE: Decrement register 1 by 1
// RETURNS: void
// ARGUMENTS:
//    - none, except R1 should have value you wish to decrement
// EFFECTS:
//    - Register 1 has been decremented by 1
//    - Program Counter has been incremented by 1

void Cpu::opDecrement1()
{
   setRegister1(getRegister1() - 1);
   incrementProgramCounter();
}

// FUNCTION: run
// PURPOSE: Loops through instructions stored in memory, and calls
//    appropriate routines to execute them.
// RETURNS: void
// ARGUMENTS: 
//    - 1. Reference to Memory object
//    - 2. Reference to Heap object
// EFFECTS: none

void Cpu::run(Memory& memory, Heap& heap)
{
   std::cout << "... Running ..." 
             << std::endl;

   while (1)
   {
      switch(memory.read(getProgramCounter()))
      {
      case 0x00:
         opHalt();
         break;
      case 0x01:
         opLoad0(memory);
         break;
      case 0x02:
         opLoad1(memory);
         break;
      case 0x03:
         opAdd();
         break;
      case 0x04:
         opStore(memory, heap);
         break;
      case 0x05:
         opPrint(memory, heap);
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
         opJumpEqual(memory);
         break;
      case 0x0B:
         opJumpNotEqual(memory);
         break;
      case 0x0C:
         opJumpLessThan(memory);
         break;
      case 0x0D:
         opJumpGreaterThan(memory);
         break;
      case 0x0E:
         opCall(memory);
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
         opJumpNotZero(memory);
         break;
      case 0x13:
         opJump(memory);
         break;
      case 0x14:
         opJumpZero(memory);
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
         std::cout << "ERROR: Bad OpCode" 
                   << std::endl;
      }

      if (isHalt())
      {
         break;
      }
   }
}
