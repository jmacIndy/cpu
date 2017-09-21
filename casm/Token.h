#ifndef TOKEN__H
#define TOKEN__H

#include <iostream>
#include <string>
#include <map>

typedef std::string TokenType;

class Token
{

   private:

      TokenType token;
      std::string literal;

   public:

      static const TokenType WRONG;
      static const TokenType ENDFILE;

      static const TokenType COMMENT;

      // Identifiers + literals
      static const TokenType IDENT;
      static const TokenType NUMINT;
      static const TokenType NUMHEX;

      // Delimiters
      static const TokenType COMMA;

      // Keywords
      static const TokenType HALT;
      static const TokenType SET0;
      static const TokenType SET1;
      static const TokenType LD0;
      static const TokenType LD1;
      static const TokenType ADD;
      static const TokenType STOR;
      static const TokenType PRT;
      static const TokenType MULT;
      static const TokenType DIV;
      static const TokenType SUB;
      static const TokenType JEQ;
      static const TokenType JNE;
      static const TokenType JLT;
      static const TokenType JGT;
      static const TokenType CALL;
      static const TokenType RET;
      static const TokenType INT;
      static const TokenType CMP;
      static const TokenType JNZ;
      static const TokenType JMP;
      static const TokenType JZ;
      static const TokenType INC0;
      static const TokenType INC1;
      static const TokenType DEC0;
      static const TokenType DEC1;
      static const TokenType TST;
      static const TokenType CONSTANT;
      static const TokenType DATA;
      static const TokenType CODE;

      static std::map<std::string, TokenType> keywords;

      void setToken(TokenType tok) { token = tok; }
      void setLiteral(std::string lit) { literal = lit; }

      TokenType getToken() const { return token; }
      std::string getLiteral() const { return literal; }

      TokenType lookupIdent(std::string);

};

#endif
