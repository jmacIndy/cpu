#ifndef HEAP__H 
#define HEAP__H

#include <iostream>
#include <iomanip>
#include <array>

typedef unsigned char byte;

class Heap
{

   private:

      static const byte HEAP_SIZE = 0xFF;

      std::array<byte, HEAP_SIZE> heap;

   public:

      Heap() { initialize(); }

      static byte getSize() { return HEAP_SIZE; }

      void initialize() { heap.fill(0x00); }

      void write(byte address, byte value) { heap[address] = value; }

      byte read(byte address) const { return heap[address]; }

      void dump() const;

};

#endif
