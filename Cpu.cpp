#include "Cpu.h"

void Cpu::initialize()
{
   setRegister0(0x00);
   setRegister1(0x00);
   setProgramCounter(0x00);
   setHeapPointer(0x00);
   resetGreaterThan();
   resetLessThan();
   resetZero();
   resetNonZero();
   resetOverflow();
   resetUnderflow();
   resetSigning();
   resetHalt();
}

void Cpu::printRegister0() const
{
   std::cout << "Register 0      : "
             << static_cast<int>(getRegister0())
             << std::endl;
}

void Cpu::printRegister1() const
{
   std::cout << "Register 1      : "
             << static_cast<int>(getRegister1())
             << std::endl;
}

void Cpu::printProgramCounter() const
{
   std::cout << "Program Counter : "
             << static_cast<int>(getProgramCounter())
             << std::endl;
}

void Cpu::printHeapPointer() const
{
   std::cout << "Heap Pointer    : "
             << static_cast<int>(getHeapPointer())
             << std::endl;
}

void Cpu::printFlags() const
{
   std::cout << "Flags           : ";
   if (isGreaterThan())
   {
      std::cout << "GreaterThan ";
   }
   if (isLessThan())
   {
      std::cout << "LessThan ";
   }
   if (isZero())
   {
      std::cout << "Zero ";
   }
   if (isNonZero())
   {
      std::cout << "NonZero ";
   }
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

void Cpu::pushState(Stack &stack)
{
   stack.push(getRegister0());
   stack.push(getRegister1());
   stack.push(getProgramCounter());
   stack.push(getHeapPointer());
//   stack.push(flags);
}

void Cpu::popState(Stack &stack)
{
//   flags = stack.pop();
   setHeapPointer(stack.pop());
   setProgramCounter(stack.pop());
   setRegister1(stack.pop());
   setRegister0(stack.pop());
}
