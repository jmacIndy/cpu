#include <iostream>
#include <fstream>
#include <string>

#include "Lexer.h"
#include "Token.h"

int main() {

   std::ifstream inFile("sample2.asm");
   std::string content ((std::istreambuf_iterator<char>(inFile)),
      (std::istreambuf_iterator<char>()));

   Lexer lexer(content);

   for (auto tok = lexer.nextToken(); 
        tok.getToken() != Token::ENDFILE; 
        tok = lexer.nextToken()) {
      std::cout << "Token " 
                << tok.getToken() 
                << " Literal " 
                << tok.getLiteral()
                << std::endl;
   }

   return 0;
}
