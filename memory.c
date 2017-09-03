#include "memory.h"

void clearMemory()
{
   int i;

   for (i = 0; i < MEMORY_SIZE; i++)
   {
      memory[i] = 0x00;
   }
}

void writeMemory(byte address, byte value)
{
   memory[address] = value;
}

byte readMemory(byte address)
{
   return memory[address];
}

void dumpMemory()
{
   int i, j;

   int addressCounter = 0x00;

   printf("\nMemory Contents:\n");
   printf("----------------");

   for (i = 0x00, j = 0x00; i < MEMORY_SIZE; i++, j++)
   {
      if ((j % 0x0F) == 0x00)
      {
         printf("\nAddress(%02X) ", addressCounter);
         addressCounter += 0x0F;
      }
      printf("%02X ", memory[i]);
   }

   printf("\n\n");
}
