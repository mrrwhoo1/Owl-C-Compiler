#include <iostream>
#include <string>

int main() {
    std::cout<<"Owl-C interpreter v1.0.1"<<std::endl;
    std::cout<<"Type 'exit' to quit."<<std::endl;

    std::string input;
    while (true) {
    std::cout<<">> ";
    if(!std::getline(std::cin, input) || input == "exit") break;
    std::cout<<"Echo: "<<input<<std::endl;
    }
return 0;
}