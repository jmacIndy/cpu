#include "Bios.h"

void Bios::handleInterrupt(byte interruptCode, byte interruptType,
   byte value) 
{

    if (interruptCode == 0x01) {
        if (interruptType == 0x01) {
            readKeyboard();
        } else {
           std::cout << "ERROR: Invalid interrupt type code!"
                     << std::endl;
        }
    } else if (interruptCode == 0x02) {
        if (interruptType == 0x01) {
            writeNumberToDisplay(value);
        } else if (interruptType == 0x02) {
            writeCharToDisplay(value);
        } else if (interruptType == 0x03) {
            writeStringToDisplay(value);
        } else {
           std::cout << "ERROR: Invalid interrupt type code!"
                     << std::endl;
        }
    } else {
        std::cout << "ERROR: Invalid interrupt code!"
                  << std::endl;
    }
}

void Bios::readKeyboard() 
{
}

void Bios::writeNumberToDisplay(byte value) 
{

   std::cout << value
             << std::endl;
   // printf("%02X\n", value);
}

void Bios::writeCharToDisplay(byte value) 
{
   std::cout << value
             << std::endl;
   // printf("%c\n", value);
}

void Bios::writeStringToDisplay(byte value) 
{
}
