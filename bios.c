#include "bios.h"

void handleInterrupt(byte interruptCode, byte interruptType,
   byte value) {

    if (interruptCode == 0x01) {
        if (interruptType == 0x01) {
            readKeyboard();
        } else {
           printf("ERROR: Invalid interrupt type code!\n");
        }
    } else if (interruptCode == 0x02) {
        if (interruptType == 0x01) {
            writeNumberToDisplay(value);
        } else if (interruptType == 0x02) {
            writeCharToDisplay(value);
        } else if (interruptType == 0x03) {
            writeStringToDisplay(value);
        } else {
           printf("ERROR: Invalid interrupt type code!\n");
        }
    } else {
        printf("ERROR: Invalid interrupt code!\n");
    }
}

void readKeyboard() {
   ;
}

void writeNumberToDisplay(byte value) {

   printf("%02X\n", value);
}

void writeCharToDisplay(byte value) {
   printf("%c\n", value);
}

void writeStringToDisplay(byte value) {
   ;
}
