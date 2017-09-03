#ifndef OPS__H
#define OPS__H

#include <stdio.h>

#include "cpu.h"
#include "memory.h"
#include "heap.h"
#include "stack.h"

typedef unsigned char byte;

void opHalt();            // HALT opcode 0x00
void opLoad0();           // LDR0 opcode 0x01
void opLoad1();           // LDR1 opcode 0x02
void opAdd();             // ADD  opcode 0x03
void opStore();           // STOR opcode 0x04
void opPrint();           // PRT  opcode 0x05
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
