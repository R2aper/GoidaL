#include <iostream>
#include <string>
#include <vector>

#include "../include/Token.hpp"
#include "../include/Lexer.hpp"


Lexer::Lexer(std::wstring code) {
    this->code = code;
}

std::vector<Token> Lexer::CodeAnalysis() {
    while(pos < code.length()) {
    if(std::isspace(code[pos])) {
        pos++;
        continue;
    }
    if(code[pos] == L'+' || code[pos] == L'-' || code[pos] == L'*' || code[pos] == L'/') {
        tokens.push_back(Token(TokenType::OPERATOR, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L'=') {
        tokens.push_back(Token(TokenType::ASSIGN, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L')') {
        tokens.push_back(Token(TokenType::RPAREN, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos]== L'(') {
        tokens.push_back(Token(TokenType::LPAREN, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L'[') {
        tokens.push_back(Token(TokenType::LSBRACKET, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L']') {
        tokens.push_back(Token(TokenType::RSBRACKET, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L'[') {
        tokens.push_back(Token(TokenType::LBRACKET, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L']') {
        tokens.push_back(Token(TokenType::RBRACKET, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L',') {
        tokens.push_back(Token(TokenType::COMMA, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L'.') {
        tokens.push_back(Token(TokenType::DOT, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if(code[pos] == L';') {
        tokens.push_back(Token(TokenType::SEMICOLON, std::wstring(1, code[pos]), pos));
        pos++;
        continue;
    }
    if (code[pos]>= L'А' && code[pos] <= L'я' || std::isalpha(code[pos])) {
        std::wstring id;
        while(pos < code.length() && (code[pos]>= L'А' && code[pos] <= L'я' || std::isalpha(code[pos]) ) || std::isdigit(code[pos]) || code[pos] == L'_') {
            id+=code[pos];
            pos++;
        }
        if(id == L"целое" || id == L"плав" || id == L"строка") {
            tokens.push_back(Token(TokenType::DATATYPE, id, pos-id.length()));
            continue;
        }
        tokens.push_back(Token(TokenType::VAR, id, pos - id.length()));
        continue;
    }
    if(std::isdigit(code[pos])) {
        std::wstring num;
        while(pos < code.length() && std::isdigit(code[pos])) {
            num+=code[pos];
            pos++;
        }
        tokens.push_back(Token(TokenType::NUMBER, num, pos));
        continue;
    }
    std::cerr << "Unknown character: " << code[pos] <<"Position: " << pos <<  std::endl;
    tokens.push_back(Token(TokenType::UNKNOWN, std::wstring(1, code[pos]), pos++));
}

tokens.push_back(Token(TokenType::END, L"", pos));
return tokens;
}
