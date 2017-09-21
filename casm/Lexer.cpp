#include "Lexer.h"

Token Lexer::nextToken() {

   Token tok;
   skipWhitespace();

   switch (getCh())
   {
      case ',': {
         tok.setToken(Token::COMMA);
         std::string s(1,getCh());
         tok.setLiteral(s);
         break;
      }
      case '.': {
         setCh(readChar());
         tok.setLiteral(readIdentifier());
         tok.setToken(tok.lookupIdent(tok.getLiteral()));
         return tok;
         break;
      }
      case '/': {
         if (peekChar() == '/') {
            skipComments();
            tok.setLiteral("");
            tok.setToken(Token::COMMENT);
            return tok;
            break;
         }
      }
      case 0: {
         tok.setToken(Token::ENDFILE);
         tok.setLiteral("");
         break;
      }
      default:
         if (isLetter(getCh())) {
            tok.setLiteral(readIdentifier());
            tok.setToken(tok.lookupIdent(tok.getLiteral()));
            return tok;
         } else if (isDigit(getCh())) {
            if (getCh() == '0' && (peekChar() == 'x' || peekChar() == 'X')) {
               tok.setToken(Token::NUMHEX);
               tok.setLiteral(readHexNumber());
               return tok;
            } else {
               tok.setToken(Token::NUMINT);
               tok.setLiteral(readNumber());
               return tok;
            }
         } else {
            tok.setToken(Token::WRONG);
            std::string s(1,getCh());
            tok.setLiteral(s); 
         }
         break;
   }

   setCh(readChar());
   return tok;
}

void Lexer::skipWhitespace() {
   char next = getCh();
   while (next == ' ' || next == '\t' || next == '\n' || next == '\r') {
      setCh(readChar());
      next = getCh();
   }
}

void Lexer::skipComments() {
   char next = getCh();
   while (next != '\n') {
      setCh(readChar());
      next = getCh();
   }
}

char Lexer::readChar() {
   char next;
   if (getReadPosition() >= getInput().length()) {
      next = 0;
   } else {
      next = input[getReadPosition()];
   }

   setPosition(getReadPosition());
   incrementReadPosition();

   return next;
}

char Lexer::peekChar() const {
   if (getReadPosition() >= getInput().length()) {
      return 0;
   } else {
      return input[getReadPosition()];
   }
}

std::string Lexer::readIdentifier() {
   int pos = getPosition();

   while (isLetter(getCh()) || isDigit(getCh())) {
      setCh(readChar());
   }
   return input.substr(pos, getPosition() - pos);
}

std::string Lexer::readNumber() {
   int pos = getPosition();

   while (isDigit(getCh())) {
      setCh(readChar());
   }

   return input.substr(pos, getPosition() - pos);
}

std::string Lexer::readHexNumber() {
   int pos = getPosition();

   while (isHexDigit(getCh())) {
      setCh(readChar());
   }

   return input.substr(pos, getPosition() - pos);
}

bool isLetter(char ch) {
   return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch) {
   return (ch >= '0' && ch <= '9');
}

bool isHexDigit(char ch) {
   return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') ||
          (ch >= 'a' && ch <= 'f') || (ch == 'x') || (ch == 'X');
}
