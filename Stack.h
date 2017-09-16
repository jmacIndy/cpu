#ifndef STACK__H 
#define STACK__H

#include <iostream>
#include <iomanip>
#include <array>

typedef unsigned char byte;

class Stack
{
   private:

      static const byte STACK_SIZE = 0xFF;

      std::array<byte, STACK_SIZE> stack;

      byte stackPointer;

   public:

      Stack() { initialize(); }

      static byte getSize() { return STACK_SIZE; }

      void initialize() { stack.fill(0x00); }

      void push(byte value) { stack[stackPointer++] = value; }

      byte pop() { return stack[--stackPointer]; }

      void dump() const;

};

#endif
