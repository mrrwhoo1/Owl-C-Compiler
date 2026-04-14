//first try at the lexer
#include <iostream>
#include <vector>
#include <string>




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
         if (next_char_pos >= input.size()) {
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


};


int main() {
    LexerTest myTest("Hello just testing");
    myTest.ReadChar();

    while (myTest.ch != 0) {
        myTest.SkipWhiteSpaces();
        if (myTest.ch == '\0') break;

        std::cout <<"Char: ["<< myTest.ch <<"] at index: "<<myTest.current_char_pos<<std::endl;
        myTest.ReadChar();
    }


    return 0;

}