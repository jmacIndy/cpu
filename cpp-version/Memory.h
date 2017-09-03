#ifndef MEMORY__H
#define MEMORY__H

#include <iostream>
#include <iomanip>
#include <array>

typedef unsigned char byte;

class Memory
{
   private:

      static const byte MEMORY_SIZE = 0xFF;

      std::array<byte, MEMORY_SIZE> memory;

   public:
      Memory() { initialize(); }

      void initialize() { memory.fill(0x00); }
     
      static byte getSize() { return MEMORY_SIZE; } 

      void write(byte address, byte value) { memory[address] = value; }
      byte read(byte address) const { return memory[address]; }

      void dump() const;

};

#endif
