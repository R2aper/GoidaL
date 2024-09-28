#pragma once

#include <string>

enum class TokenType
{
    DATATYPE,
    NUMBER,
    VAR,
    ASSIGN,
    OPERATOR,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    LSBRACKET,
    RSBRACKET,
    COMMA,
    SEMICOLON,
    DOT,
    UNKNOWN,
    END,
}; 

class Token {
public:
    TokenType type;
    std::string value;
    int pos;

    Token(TokenType type, std::string value, int pos);

    std::string TypetoString();

};