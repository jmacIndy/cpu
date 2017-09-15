#ifndef MEMORY__H
#define MEMORY__H

#include <stdio.h>

#define MEMORY_SIZE 0xFF

typedef unsigned char byte;

byte memory[MEMORY_SIZE];

void clearMemory();

void writeMemory(byte address, byte value);

byte readMemory(byte address);

void dumpMemory();

#endif
