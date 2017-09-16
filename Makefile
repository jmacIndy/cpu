all: cpuc

cpuc: main.o Memory.o Cpu.o Heap.o Stack.o Ops.o Bios.o
	g++ main.o Cpu.o Memory.o Heap.o Stack.o Ops.o Bios.o -o ~/bin/cpuc

main.o: main.cpp Cpu.h Memory.h Heap.h Stack.h Ops.h
	g++ -c -std=c++11 main.cpp

Cpu.o: Cpu.cpp Cpu.h Stack.h
	g++ -c -std=c++11 Cpu.cpp

Memory.o: Memory.cpp Memory.h
	g++ -c -std=c++11 Memory.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c -std=c++11 Heap.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c -std=c++11 Stack.cpp

Ops.o: Ops.cpp Ops.h Memory.h Cpu.h Heap.h Stack.h Bios.h
	g++ -c -std=c++11 Ops.cpp

Bios.o: Bios.cpp Bios.h
	g++ -c -std=c++11 Bios.cpp
