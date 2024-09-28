#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../include/Lexer.hpp"
#include "../include/Token.hpp"

void usage() {
    printf("Goida - piece of code   \n \
    Usage: Goida <path to file> or Goida \n");
}


std::string readFromFile(std::string path) {
    std::string code;
    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            code += line;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
        code = "";
    }
    return code;

}

int main(int argc, char* argv[]) {
    if ( argc > 2) {
        usage();
        return 1;
    }

    std::string code;

    if (argc == 2) {
        code = readFromFile(argv[1]);
        if(code.empty()) { 
            return 1;
        }
    }

    if(argc != 2) {
        printf("Enter code:\n");
        std::getline(std::cin, code);
    }

    Lexer lexer(code);

    std::vector <Token> tokens =  lexer.CodeAnalysis();

    std::cout << code << std::endl;
    for (int i = 0; i < tokens.size(); i++) {
      std::cout <<"|" << tokens[i].value << "|" << tokens[i].pos << "|"<<tokens[i].TypetoString() << "|" <<  std::endl;
    }

}