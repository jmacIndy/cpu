#ifndef CPU__H
#define CPU__H

#include <iostream>
#include <iomanip>

#include "Stack.h"

typedef unsigned char byte;

class Cpu
{
   private:

      byte register0;
      byte register1;
      byte programCounter;
      byte heapPointer;

      // flags:
      // 0 = greater than
      // 1 = less than
      // 2 = zero
      // 3 = non zero
      // 4 = overflow
      // 5 = underflow
      // 6 = signing
      // 7 = halt

      byte flags;

      static const byte greaterThanSet = 0x80;
      static const byte lessThanSet = 0x40;
      static const byte zeroSet = 0x20;
      static const byte nonZeroSet = 0x10;
      static const byte overflowSet = 0x08;
      static const byte underflowSet = 0x04;
      static const byte signingSet = 0x02;
      static const byte haltSet = 0x01;

      static const byte greaterThanReset = 0x7F;
      static const byte lessThanReset = 0xBF;
      static const byte zeroReset = 0xDF;
      static const byte nonZeroReset = 0xEF;
      static const byte overflowReset = 0xF7;
      static const byte underflowReset = 0xFB;
      static const byte signingReset = 0xFD;
      static const byte haltReset = 0xFE;

   public:

      Cpu() { initialize(); }

      void initialize();

      void setRegister0(byte value) { register0 = value; }
      void setRegister1(byte value) { register1 = value; }

      void setProgramCounter(byte value) { programCounter = value; }
      void setHeapPointer(byte value) { heapPointer = value; }

      void setGreaterThan() { flags = flags | greaterThanSet; }
      void setLessThan() { flags = flags | lessThanSet; }
      void setZero() { flags = flags | zeroSet; }
      void setNonZero() { flags = flags | nonZeroSet; }
      void setOverflow() { flags = flags | overflowSet; }
      void setUnderflow() { flags = flags | underflowSet; }
      void setSigning() { flags = flags | signingSet; }
      void setHalt() { flags = flags | haltSet; }

      void resetGreaterThan() { flags = flags & greaterThanReset; }
      void resetLessThan() { flags = flags & lessThanReset; }
      void resetZero() { flags = flags & zeroReset; }
      void resetNonZero() { flags = flags & nonZeroReset; }
      void resetOverflow() { flags = flags & overflowReset; }
      void resetUnderflow() { flags = flags & underflowReset; }
      void resetSigning() {flags = flags & signingReset; }
      void resetHalt() { flags = flags & haltReset; }

      bool isGreaterThan() const { return flags & greaterThanSet; }
      bool isLessThan() const { return flags & lessThanSet; }
      bool isZero() const { return flags & zeroSet; }
      bool isNonZero() const { return flags & nonZeroSet; }
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

      void pushState(Stack &stack);
      void popState(Stack &stack);

};

#endif
