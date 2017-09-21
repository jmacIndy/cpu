all: casm

casm: main.o Lexer.o Token.o
	g++ main.o Lexer.o Token.o -o ~/bin/casm

main.o: main.cpp Lexer.h Token.h
	g++ -c -std=c++11 main.cpp

Lexer.o: Lexer.cpp Lexer.h Token.h
	g++ -c -std=c++11 Lexer.cpp

Token.o: Token.cpp Token.h
	g++ -c -std=c++11 Token.cpp
