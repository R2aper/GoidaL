#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer {
private:
    std::wstring code;
    std::vector<Token> tokens;
    int pos = 0;

public:
    Lexer(std::wstring code);

    std::vector<Token> CodeAnalysis();

};