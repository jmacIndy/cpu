#include "stack.h"

void clearStack()
{
   int i;

   stackPointer = 0x00;

   for (i = 0; i < STACK_SIZE; i++)
   {
      stack[i] = 0x00;
   }
}

void push(byte value)
{
   stack[stackPointer++] = value;
}

byte pop()
{
   return stack[--stackPointer];
}

void dumpStack()
{
   int i, j;

   int addressCounter = 0x00;

   printf("\nStack Contents:\n");
   printf("---------------\n");
   printf("   Stack Pointer: %02X\n", stackPointer);
   printf("---------------");

   for (i = 0x00, j = 0x00; i < STACK_SIZE; i++, j++)
   {
      if ((j % 0x0F) == 0x00)
      {
         printf("\nAddress(%02X) ", addressCounter);
         addressCounter += 0x0F;
      }
      printf("%02X ", stack[i]);
   }

   printf("\n\n");
}
