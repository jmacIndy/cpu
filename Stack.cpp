#include "Stack.h"

void Stack::dump() const
{
   int addressCounter = 0x00;

   std::cout << "Stack Contents: "
             << std::endl
             << "---------------"
             << std::endl
             << "   Stack Pointer: "
             << std::hex
             << static_cast<int>(stackPointer);

   int j = 0x00;

   for (auto i = stack.begin(); i != stack.end(); i++, j++)
   {
      if ((j % 0x0F) == 0x00)
      {
         std::cout << std::endl
                   << "Address("
                   << std::setw(2)
                   << std::setfill('0')
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
