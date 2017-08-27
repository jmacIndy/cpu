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

      void initialize() { heap.fill(0x00); }
     
      static byte getHeapSize() { return HEAP_SIZE; } 

      void write(byte address, byte value) { heap[address] = value; }
      byte read(byte address) const { return heap[address]; }

      void dump() const;
};

#endif
