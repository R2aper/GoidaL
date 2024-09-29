#include <iostream>
#include <string>
#include <vector>
#include <fstream>


#include "../include/Lexer.hpp"
#include "../include/Token.hpp"

void usage() {
    printf("Goida - piece of code\n\
Usage: Goida <path to file>\n\
The file need to be in ANSI format \n");
}

/*
TODO:
- Добавить поддержку русского языка
- Добавить токены для ' " 
- UTF-8 to ANSCI

*/

std::wstring readFromFile(std::string path) {
    std::wstring code;
    std::wifstream file(path);
    if (file.is_open()) {
        std::wstring line;
        while (std::getline(file, line)) {
            code += line;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
        code = L"";
    }
    return code;

}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL,"RUS");
    if ( argc != 2) {
        usage();
        return 1;
    }

    std::wstring code;

    if (argc == 2) {
        code = readFromFile(argv[1]);
        if(code.empty()) { 
            return 1;
        }
    }

   Lexer lexer(code);

   std::vector <Token> tokens =  lexer.CodeAnalysis();

    for (int i = 0; i < tokens.size(); i++) {
        std::wcout << tokens[i].TypetoWstring() << L" ";
    }

}