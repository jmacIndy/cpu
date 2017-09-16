#ifndef BIOS__H
#define BIOS__H

#include <iostream>

typedef unsigned char byte;

class Bios
{
   public:

      void handleInterrupt(byte interruptCode, byte interruptType,
         byte value);

      void readKeyboard();

      void writeNumberToDisplay(byte value);

      void writeCharToDisplay(byte value);

      void writeStringToDisplay(byte value);

};

#endif
