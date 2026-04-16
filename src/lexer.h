#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <string>

class Lexer {
    public:
        Lexer(std::string input);
        Token NextToken();

    private:
        std::string input;
        size_t current_char_pos; //index of current
        size_t next_char_pos;
        char ch;

        void ReadChar();
        void SkipWhiteSpaces();
        std::string CaptureIdentifier();
        std::string CaptureNumber();

};

#endif
