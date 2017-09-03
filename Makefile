all: cpuc

cpuc: main.o memory.o cpu.o heap.o stack.o
	gcc main.o cpu.o memory.o heap.o stack.o -o ~/bin/cpuc

main.o: main.c cpu.h memory.h heap.h stack.h
	gcc -c main.c

cpu.o: cpu.c cpu.h memory.h heap.h stack.h
	gcc -c cpu.c

memory.o: memory.c memory.h
	gcc -c memory.c

heap.o: heap.c heap.h
	gcc -c heap.c

stack.o: stack.c stack.h
	gcc -c stack.c
