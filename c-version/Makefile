all: cpuc assembler

cpuc: main.o memory.o cpu.o heap.o stack.o ops.o bios.o
	gcc main.o cpu.o memory.o heap.o stack.o ops.o bios.o -o ~/bin/cpuc

assembler: assembler.o
	gcc assembler.o -o ~/bin/assembler

main.o: main.c cpu.h memory.h heap.h stack.h ops.h
	gcc -c main.c

ops.o: ops.c ops.h cpu.h memory.h heap.h stack.h bios.h
	gcc -c ops.c

cpu.o: cpu.c cpu.h
	gcc -c cpu.c

memory.o: memory.c memory.h
	gcc -c memory.c

heap.o: heap.c heap.h
	gcc -c heap.c

stack.o: stack.c stack.h
	gcc -c stack.c

assembler.o: assembler.c
	gcc -c assembler.c

bios.o: bios.c bios.h
	gcc -c bios.c
