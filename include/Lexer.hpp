#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer {
private:
    std::wstring code;
    std::vector<Token> tokens;
    unsigned int pos = 0;

public:
    Lexer(std::wstring code);

    std::vector<Token> CodeAnalysis();

};
    
bool isDataType(std::wstring input);
bool isOperator(std::wstring input);
bool isVar(std::wstring input);

