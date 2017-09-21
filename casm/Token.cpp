#include "Token.h"

const TokenType Token::WRONG = "WRONG";
const TokenType Token::ENDFILE = "ENDFILE";

const TokenType Token::COMMENT = "//";

// Identifiers + literals
const TokenType Token::IDENT = "IDENT";
const TokenType Token::NUMINT = "NUMINT";
const TokenType Token::NUMHEX = "NUMHEX";

// Delimiters
const TokenType Token::COMMA = ",";

// Keywords
const TokenType Token::HALT = "HALT";
const TokenType Token::SET0 = "SET0";
const TokenType Token::SET1 = "SET1";
const TokenType Token::LD0  = "LD0";
const TokenType Token::LD1  = "LD1";
const TokenType Token::ADD  = "ADD";
const TokenType Token::STOR = "STOR";
const TokenType Token::PRT  = "PRT";
const TokenType Token::MULT = "MULT";
const TokenType Token::DIV  = "DIV";
const TokenType Token::SUB  = "SUB";
const TokenType Token::JEQ  = "JEQ";
const TokenType Token::JNE  = "JNE";
const TokenType Token::JLT  = "JLT";
const TokenType Token::JGT  = "JGT";
const TokenType Token::CALL = "CALL";
const TokenType Token::RET  = "RET";
const TokenType Token::INT  = "INT";
const TokenType Token::CMP  = "CMP";
const TokenType Token::JNZ  = "JNZ";
const TokenType Token::JMP  = "JMP";
const TokenType Token::JZ   = "JZ";
const TokenType Token::INC0 = "INC0";
const TokenType Token::INC1 = "INC1";
const TokenType Token::DEC0 = "DEC0";
const TokenType Token::DEC1 = "DEC1";
const TokenType Token::TST  = "TST";
const TokenType Token::CONSTANT = "CONSTANT";
const TokenType Token::DATA     = "DATA";
const TokenType Token::CODE     = "CODE";

std::map<std::string, TokenType> Token::keywords = {
   {"HALT", HALT},
   {"SET0", SET0},
   {"SET1", SET1},
   {"LD0", LD0},
   {"LD1", LD1},
   {"ADD", ADD},
   {"STOR", STOR},
   {"PRT", PRT},
   {"MULT", MULT},
   {"DIV", DIV},
   {"SUB", SUB},
   {"JEQ", JEQ},
   {"JNE", JNE},
   {"JLT", JLT},
   {"JGT", JGT},
   {"CALL", CALL},
   {"RET", RET},
   {"INT", INT},
   {"CMP", CMP},
   {"JNZ", JNZ},
   {"JMP", JMP},
   {"JZ", JZ},
   {"INC0", INC0},
   {"INC1", INC1},
   {"DEC0", DEC0},
   {"DEC1", DEC1},
   {"TST", TST},
   {"CONSTANT", CONSTANT},
   {"DATA", DATA},
   {"CODE", CODE}
};

TokenType Token::lookupIdent(std::string ident) {

   auto search = keywords.find(ident);
   if (search == keywords.end())
   {
      return IDENT;
   }
   else
   {
      return search->second;
   }
}
