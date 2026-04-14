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


   
};


int main() {
    LexerTest myTest("Hello just testing 124 8782 1 +_)()");
    myTest.ReadChar();

    while (myTest.ch != '\0') {
        myTest.SkipWhiteSpaces();
        if (myTest.ch == '\0') break;

        if (std::isalpha(myTest.ch)) {
            std::string word = myTest.CaptureIdentifier();
            std::cout<<"found word: "<<word<<std::endl;
            
        }
        else if (isdigit(myTest.ch)){
            std::string num = myTest.CaptureNumber();
            std::cout<<"found number: "<<num<<std::endl;
        }

        else {
            myTest.ReadChar();
        }

    }


    return 0;

}