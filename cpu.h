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
       0 = greater than
       1 = less than
       2 = zero
       3 = non zero
       4 = overflow
       5 = underflow
       6 = signing
       7 = halt
*/

byte flags;

#define GREATERTHAN_SET 0x80
#define LESSTHAN_SET 0x40
#define ZERO_SET 0x20
#define NONZERO_SET 0x10
#define OVERFLOW_SET 0x08
#define UNDERFLOW_SET 0x04
#define SIGNING_SET 0x02
#define HALT_SET 0x01

#define GREATERTHAN_RESET 0x7F
#define LESSTHAN_RESET 0xBF
#define ZERO_RESET 0xDF
#define NONZERO_RESET 0xEF
#define OVERFLOW_RESET 0xF7
#define UNDERFLOW_RESET 0xFB
#define SIGNING_RESET 0xFD
#define HALT_RESET 0xFE

void initializeCPU();

void setGreaterThan();
void setLessThan();
void setZero();
void setNonZero();
void setOverflow();
void setUnderflow();
void setSigning();
void setHalt();

void resetGreaterThan();
void resetLessThan();
void resetZero();
void resetNonZero();
void resetOverflow();
void resetUnderflow();
void resetSigning();
void resetHalt();

int isGreaterThan();
int isLessThan();
int isZero();
int isNonZero();
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
