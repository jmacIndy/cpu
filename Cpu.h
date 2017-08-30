#ifndef CPU__H
#define CPU__H

#include <iostream>
#include <iomanip>
#include <stack>
#include <array>

#include "Memory.h"
#include "Heap.h"

typedef unsigned char byte;

class Cpu
{
   private:

      byte register0;
      byte register1;
      byte programCounter;
      byte heapPointer;

      std::stack<byte> stack;

      // flags:
      // 0 - 3 = unused
      //     4 = overflow
      //     5 = underflow
      //     6 = signing
      //     7 = halt
      byte flags;

      static const byte overflowSet = 0x08;
      static const byte overflowReset = 0xF7;
      static const byte underflowSet = 0x04;
      static const byte underflowReset = 0xFB;
      static const byte signingSet = 0x02;
      static const byte signingReset = 0xFD;
      static const byte haltSet = 0x01;
      static const byte haltReset = 0xFE;

   public:
      Cpu() { initialize(); }

      void initialize();
     
      void setRegister0(byte value) { register0 = value; }
      void setRegister1(byte value) { register1 = value; }

      void setProgramCounter(byte value) { programCounter = value; }
      void setHeapPointer(byte value) { heapPointer = value; }

      void setOverflow() { flags = flags | overflowSet; }
      void setUnderflow() { flags = flags | underflowSet; }
      void setSigning() { flags = flags | signingSet; }
      void setHalt() { flags = flags | haltSet; }

      void resetOverflow() { flags = flags & overflowReset; }
      void resetUnderflow() { flags = flags & underflowReset; }
      void resetSigning() { flags = flags & signingReset; }
      void resetHalt() { flags = flags & haltReset; }

      bool isOverflow() const { return flags & overflowSet; }
      bool isUnderflow() const { return flags & underflowSet; }
      bool isSigning() const { return flags & signingSet; }
      bool isHalt() const { return flags & haltSet; }

      byte getRegister0() const { return register0; }
      byte getRegister1() const { return register1; }

      byte getProgramCounter() const { return programCounter; }
      byte getHeapPointer() const { return heapPointer; }

      void incrementProgramCounter() { programCounter++; }

      void printRegister0() const;
      void printRegister1() const;

      void printProgramCounter() const;
      void printHeapPointer() const;

      void printFlags() const;

      void dump() const;

      void opHalt();                   // HALT opcode 0x00
      void opLoad0(Memory&);           // LDR0 opcode 0x01
      void opLoad1(Memory&);           // LDR1 opcode 0x02
      void opAdd();                    // ADD  opcode 0x03
      void opStore(Memory&, Heap&);    // STOR opcode 0x04
      void opPrint(Memory&, Heap&);    // PRT  opcode 0x05
      void opBeep();                   // BEEP opcode 0x06
      void opMultiply();               // MULT opcode 0x07
      void opDivide();                 // DIV  opcode 0x08
      void opSubtract();               // SUB  opcode 0x09
      void opJumpEqual(Memory&);       // JEQ  opcode 0x0A
      void opJumpNotEqual(Memory&);    // JNE  opcode 0x0B
      void opJumpLessThan(Memory&);    // JLT  opcode 0x0C
      void opJumpGreaterThan(Memory&); // JGT  opcode 0x0D
      void opCall(Memory&);            // CALL opcode 0x0E
      void opReturn();                 // RET  opcode 0x0F
      void opInterrupt();              // INT  opcode 0x10
      void opCompare();                // CMP  opcode 0x11
      void opJumpNotZero(Memory&);     // JNZ  opcode 0x12
      void opJump(Memory&);            // JMP  opcode 0x13
      void opJumpZero(Memory&);        // JZ   opcode 0x14
      void opIncrement0();             // INC0 opcode 0x15
      void opIncrement1();             // INC1 opcode 0x16
      void opDecrement0();             // DEC0 opcode 0x17
      void opDecrement1();             // DEC1 opcode 0x18

      void run(Memory& memory, Heap& heap);
};

#endif
