//first try at the lexer


/*Objectives:
Implement a character reading function so it moves through without crashng. [✓]
add a filter function to ignore what spaces etc. [✓]
Add word recognition, move from printing single characters to identifying Identifiers etc. [✓]
turn characters into digits [✓]
Add a token struct that will show the type and literal
*/
#include <iostream>
#include <vector>
#include <string>
// #include <any>
#include <cctype>


struct Token {
        std::string type;
        std::string literal;
    };

class LexerTest {
public:

    

    std::string input;
    size_t current_char_pos; //index of current
    size_t next_char_pos; //next
    char ch; //curren character being looked at.

    LexerTest(std::string StrInput) {
        input = StrInput;
        current_char_pos  = 0;
        next_char_pos = 0;
        ch = '\0';

        //ReadChar();
    }



    void ReadChar() {
        //Tasks
        // 1. Check if readPosition has reached the end of 'input'
        // 2. If it has, set 'ch' to 0 (or '\0')
        // 3. Otherwise, set 'ch' to the character at 'readPosition'
        // 4. Update 'position' to 'readPosition'
        // 5. Increment 'readPosition' by 1
         if (next_char_pos > input.size()) {
            ch = '\0';
         }
         else {
            ch = input[next_char_pos];
            current_char_pos = next_char_pos;
            next_char_pos++;
         }

    }

    void SkipWhiteSpaces() {
        while (ch == ' ' || ch == '\t' || ch =='\n' || ch == '\r' ) {
            ReadChar();
        }
        
    }
    

    std::string CaptureIdentifier() {
        // std::vector<std::any>  incase i ever decide to make this Capture multiple stuff
        size_t start= current_char_pos;

        while (std::isalpha(ch)) {
            ReadChar();
        }
        size_t length = current_char_pos - start;

        return input.substr(start, length);
    }

    std::string CaptureNumber(){
        size_t start = current_char_pos;
        while(isdigit(ch)) {
            ReadChar();
        }
        size_t length = current_char_pos - start;
        return input.substr(start, current_char_pos - start);

    }


    

    Token NextToken() {
        Token tok;
        SkipWhiteSpaces();

        switch (ch)
        {
        case '+':
            tok = {"PlUS", "+"};
            break;
        case '-':
            tok = {"MINUS", "-"};
            break;
        case '=':
            tok = {"ASSIGN", "="};
            break;
        case '*':
            tok = {"MULTIPLY", "-"};
            break;
        case '/':
            tok = {"DIVIDE", "/"};
            break;
        case '\0':
            tok = {"EOF", ""}; //end of file
            break;
        case '(':
            tok = {"OPEN PARENTHESIS", "("};
            break;
        case ')':
            tok = {"CLOSE PARENTHESIS", ")"};
            break;
        case '_':
            tok = {"UNDERSCORE", "_"};
            break;
        
        
        default:
            if (std::isalpha(ch)) {
                tok.literal = CaptureIdentifier();
                tok.type = "IDENTIFIER";
                return tok; 
            }
            else if (std::isdigit(ch)) {
                tok.literal = CaptureNumber();
                tok.type = "NUMBER";
                return tok;
            }
            else {
                tok = {"ILLEGAL", std::string (1, ch)};

            }
            break;
            }
            
            ReadChar();
            return tok;



            
        }
    };




int main() {
    LexerTest myTest("x = Hello just testing 124 8782 1 +_)()");
    myTest.ReadChar();

    Token tok = myTest.NextToken();
    while(tok.type!="EOF") {
        std::cout<<"Token type: "<<tok.type<<"\nLiteral: "<<tok.literal<<"\n----------------------------------------------------------"<<std::endl;
        tok = myTest.NextToken();
    }

    return 0;

}