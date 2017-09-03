#include "heap.h"

void clearHeap()
{
   int i;

   for (i = 0; i < HEAP_SIZE; i++)
   {
      heap[i] = 0x00;
   }
}

void writeHeap(byte address, byte value)
{
   heap[address] = value;
}

byte readHeap(byte address)
{
   return heap[address];
}

void dumpHeap()
{
   int i, j;

   int addressCounter = 0x00;

   printf("\nHeap Contents:\n");
   printf("--------------");

   for (i = 0x00, j = 0x00; i < HEAP_SIZE; i++, j++)
   {
      if ((j % 0x0F) == 0x00)
      {
         printf("\nAddress(%02X) ", addressCounter);
         addressCounter += 0x0F;
      }
      printf("%02X ", heap[i]);
   }

   printf("\n\n");
}
