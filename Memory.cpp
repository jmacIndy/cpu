#include "Memory.h"

// FUNCTION: dumpMemory
// PURPOSE: Print out the contents of the memory (where code lives)
// RETURNS: void
// ARGUMENTS: none
// EFFECTS: none

void Memory::dump() const
{
   int addressCounter = 0x00;

   std::cout << "Memory Contents: " 
             << std::endl
             << "-----------------" 
             << std::endl;

   int j = 0x00;

   for (auto i = memory.begin(); i != memory.end(); i++, j++)
   {
      if ((j % 0x0F) == 0x00)
      {
         std::cout << std::endl
                   << "Address("
                   << std::setw(2)
                   << std::hex
                   << std::uppercase
                   << addressCounter
                   << ") ";
         addressCounter += 0x0F;
      }

      std::cout << std::setw(2)
                << std::setfill('0')
                << std::hex
                << std::uppercase
                << static_cast<int>(*i)
                << " ";
   }

   std::cout << std::endl
             << std::setfill(' ');
}
