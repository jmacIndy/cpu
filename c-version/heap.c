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
   if (address < HEAP_SIZE)
   {
      heap[address] = value;
   }
   else
   {
      printf("ERROR: Cannot write above maximum heap size!\n");
   }
}

byte readHeap(byte address)
{
   if (address < HEAP_SIZE)
   {
      return heap[address];
   }
   else
   {
      printf("ERROR: Cannot read above maximum heap size!\n");
      return 0;
   }
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
