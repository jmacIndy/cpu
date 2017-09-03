all: mycpu

mycpu: test.o Memory.o Cpu.o  Heap.o
	g++ -std=c++11 test.o Cpu.o Memory.o Heap.o -o mycpu

test.o: test.cpp Cpu.h Memory.h Heap.h
	g++ -c -std=c++11 test.cpp

Cpu.o: Cpu.cpp Cpu.h Memory.h Heap.h
	g++ -c -std=c++11 Cpu.cpp

Memory.o: Memory.cpp Memory.h
	g++ -c -std=c++11 Memory.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c -std=c++11 Heap.cpp
