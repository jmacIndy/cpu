#ifndef LEXER__H
#define LEXER__H

#include <iostream>
#include <string>

#include "Token.h"

typedef unsigned char byte;

class Lexer {

   private:

      std::string input;
      int position;
      int readPosition;
      char ch;

   public:

      Lexer() : input(), position(0), readPosition(0), ch(readChar()) {}
      Lexer(std::string const &in) : input(in), position(0), readPosition(0),
         ch(readChar()) {}

      std::string getInput() const { return input; }
      int getPosition() const { return position; }
      int getReadPosition() const { return readPosition; }
      char getCh() const { return ch; }

      void setInput(std::string value) { input = value; }
      void setPosition(int value) { position = value; }
      void setReadPosition(int value) { readPosition = value; }
      void setCh(char value) { ch = value; }

      void incrementReadPosition() { readPosition++; }

      Token nextToken();

      char readChar();

      void skipWhitespace();
      void skipComments();

      char peekChar() const;

      std::string readIdentifier();
      std::string readNumber();
      std::string readHexNumber();
};

bool isLetter(char);
bool isDigit(char);
bool isHexDigit(char);

#endif
