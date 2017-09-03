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

#endif
