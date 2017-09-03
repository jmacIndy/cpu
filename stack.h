#ifndef STACK__H 
#define STACK__H

#include <stdio.h>

#define STACK_SIZE 0xFF

typedef unsigned char byte;

byte stack[STACK_SIZE];

byte stackPointer;

void clearStack();

void push(byte value);

byte pop();

void dumpStack();

#endif
