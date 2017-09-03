#ifndef CPU__H
#define CPU__H

#include <stdio.h>

typedef unsigned char byte;

byte register0;
byte register1;
byte programCounter;
byte heapPointer;

/*
    flags:
      0 - 3 = unused
          4 = overflow
          5 = underflow
          6 = signing
          7 = halt
*/

byte flags;

#define OVERFLOW_SET 0x08
#define OVERFLOW_RESET 0xF7
#define UNDERFLOW_SET 0x04
#define UNDERFLOW_RESET 0xFB
#define SIGNING_SET 0x02
#define SIGNING_RESET 0xFD
#define HALT_SET 0x01
#define HALT_RESET 0xFE

void initializeCPU();

void setOverflow();
void setUnderflow();
void setSigning();
void setHalt();

void resetOverflow();
void resetUnderflow();
void resetSigning();
void resetHalt();

int isOverflow();
int isUnderflow();
int isSigning();
int isHalt();

void printRegister0();
void printRegister1();
void printProgramCounter();
void printHeapPointer();
void printFlags();
void dumpCPU();

void opHalt();            // HALT opcode 0x00
void opLoad0();           // LDR0 opcode 0x01
void opLoad1();           // LDR1 opcode 0x02
void opAdd();             // ADD  opcode 0x03
void opStore();           // STOR opcode 0x04
void opPrint();           // PRT  opcode 0x05
void opBeep();            // BEEP opcode 0x06
void opMultiply();        // MULT opcode 0x07
void opDivide();          // DIV  opcode 0x08
void opSubtract();        // SUB  opcode 0x09
void opJumpEqual();       // JEQ  opcode 0x0A
void opJumpNotEqual();    // JNE  opcode 0x0B
void opJumpLessThan();    // JLT  opcode 0x0C
void opJumpGreaterThan(); // JGT  opcode 0x0D
void opCall();            // CALL opcode 0x0E
void opReturn();          // RET  opcode 0x0F
void opInterrupt();       // INT  opcode 0x10
void opCompare();         // CMP  opcode 0x11
void opJumpNotZero();     // JNZ  opcode 0x12
void opJump();            // JMP  opcode 0x13
void opJumpZero();        // JZ   opcode 0x14
void opIncrement0();      // INC0 opcode 0x15
void opIncrement1();      // INC1 opcode 0x16
void opDecrement0();      // DEC0 opcode 0x17
void opDecrement1();      // DEC1 opcode 0x18

void run();

#endif
