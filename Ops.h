#ifndef OPS__H
#define OPS__H

#include <iostream>

#include "Cpu.h"
#include "Memory.h"
#include "Heap.h"
#include "Stack.h"
#include "Bios.h"

typedef unsigned char byte;

class Ops
{
   public:

      void opHalt(Cpu &);                                 // HALT opcode 0x00
      void opSet0(Cpu &, Memory &);                       // SET0 opcode 0x01
      void opSet1(Cpu &, Memory &);                       // SET1 opcode 0x02
      void opAdd(Cpu &);                                  // ADD  opcode 0x03
      void opStore(Cpu &, Memory &, Heap &);              // STOR opcode 0x04
      void opPrint(Cpu &, Memory &, Heap &);              // PRT  opcode 0x05
      void opMultiply(Cpu &);                             // MULT opcode 0x07
      void opDivide(Cpu &);                               // DIV  opcode 0x08
      void opSubtract(Cpu &);                             // SUB  opcode 0x09
      void opJumpEqual(Cpu &, Memory &);                  // JEQ  opcode 0x0A
      void opJumpNotEqual(Cpu &, Memory &);               // JNE  opcode 0x0B
      void opJumpLessThan(Cpu &, Memory &);               // JLT  opcode 0x0C
      void opJumpGreaterThan(Cpu &, Memory &);            // JGT  opcode 0x0D
      void opCall(Cpu &, Stack &, Memory &);              // CALL opcode 0x0E
      void opReturn(Cpu &, Stack &);                      // RET  opcode 0x0F
      void opInterrupt(Cpu &, Memory &, Bios &, Stack &); // INT  opcode 0x10
      void opCompare(Cpu &);                              // CMP  opcode 0x11
      void opJumpNotZero(Cpu &, Memory &);                // JNZ  opcode 0x12
      void opJump(Cpu &, Memory &);                       // JMP  opcode 0x13
      void opJumpZero(Cpu &, Memory &);                   // JZ   opcode 0x14
      void opIncrement0(Cpu &);                           // INC0 opcode 0x15
      void opIncrement1(Cpu &);                           // INC1 opcode 0x16
      void opDecrement0(Cpu &);                           // DEC0 opcode 0x17
      void opDecrement1(Cpu &);                           // DEC1 opcode 0x18
      void opLoad0(Cpu &, Heap &);                        // LD0  opcode 0x19
      void opLoad1(Cpu &, Heap &);                        // LD1  opcode 0x1A
      void opTest(Cpu &);                                 // TST  opcode 0x1B

      void run(Cpu &, Memory &, Heap &, Stack &, Bios &);

};

#endif
