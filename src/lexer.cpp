#include "lexer.h"
#include <cctype>
#include <string>

 
//Birth Giver of "lexer".
Lexer::Lexer(std::string input) {
    this -> input = input;
    this -> current_char_pos = 0;
    this -> next_char_pos = 0;
    this -> ch = '\0';

    ReadChar();

}

void Lexer::ReadChar() {
         if (next_char_pos > input.size()) {
            ch = '\0';
         }
         else {
            ch = input[next_char_pos]; }

        current_char_pos = next_char_pos;
        next_char_pos++;
         

    }

//the housekeeper, gets rid of all spaces.
void  Lexer::SkipWhiteSpaces() {
        while (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
            ReadChar();
        }
    }

//returns words like x, hello etc
std::string Lexer::CaptureIdentifier(){
        size_t start = current_char_pos;
        while (isalpha(ch)) {
            ReadChar();
        }
        return input.substr(start, current_char_pos - start);
    }

//returns digits 
std::string Lexer::CaptureNumber() {
    size_t start = current_char_pos;
    while (std::isdigit(ch)) {
        ReadChar();
    }
    return input.substr(start, current_char_pos - start);
}

//The Brain: The function main() actually calls
Token Lexer::NextToken() {
    Token tok;
    SkipWhiteSpaces();

    switch (ch) {
        case '=': tok = {"ASSIGN", "="}; break;
        case '+': tok = {"PLUS", "+"}; break;
        case '-': tok = {"MINUS", "-"}; break;
        case '*': tok = {"MULTIPLY", "*"}; break;
        case '/': tok = {"DIVIDE", "/"}; break;
        case ';': tok = {"SEMICOLON", ";"}; break;
        case '(': tok = {"LPAREN", "("}; break;
        case ')': tok = {"RPAREN", ")"}; break;
        case '\0': tok = {"EOF", ""}; break;
        
        default:
            if (std::isalpha(ch)) {
                tok.literal = CaptureIdentifier();
                tok.type = "IDENTIFIER";
                return tok; // Return early because CaptureIdentifier already calls ReadChar
            } else if (std::isdigit(ch)) {
                tok.literal = CaptureNumber();
                tok.type = "NUMBER";
                return tok; // Return early
            } else {
                tok = {"ILLEGAL", std::string(1, ch)};
            }
            break;
    }

    ReadChar(); 
    return tok;
}