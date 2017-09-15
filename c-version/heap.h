#ifndef HEAP__H 
#define HEAP__H

#include <stdio.h>

#define HEAP_SIZE 0xFF

typedef unsigned char byte;

byte heap[HEAP_SIZE];

void clearHeap();

void writeHeap(byte address, byte value);

byte readHeap(byte address);

void dumpHeap();

#endif
