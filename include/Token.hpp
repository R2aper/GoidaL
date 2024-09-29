#pragma once

#include <string>

enum class TokenType
{
    DATATYPE,
    NUMBER,
    VAR,
    ASSIGN,
    OPERATOR,
    QUOTE,
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
    std::wstring value;
    int pos;

    Token(TokenType type, std::wstring value, int pos);

    std::wstring TypetoWstring();

};