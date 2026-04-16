#include <iostream>
#include <string>
#include "lexer.h" 

int main() {
    std::cout << "Owl-C interpreter v1.0.1" << std::endl;
    std::cout << "Type 'exit' to quit." << std::endl;

    std::string input;
    while (true) {
        std::cout << ">> ";
        
        //  Get the line from the user
        if (!std::getline(std::cin, input) || input == "exit") break;

        //hiring the lexer
        Lexer lex(input); 

        //calling again
        Token tok = lex.NextToken();
        
        std::cout << "--------------------------" << std::endl;
        while (tok.type != "EOF") {
            std::cout << "Type: " << tok.type << " | Literal: " << tok.literal << std::endl;
            
            
            tok = lex.NextToken();
        }
        std::cout << "--------------------------" << std::endl;
    }

    return 0;
}