#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer {
private:
    std::string code;
    std::vector<Token> tokens;
    int pos = 0;

public:
    Lexer(std::string code);

    std::vector<Token> CodeAnalysis();

};