#include <iostream>
#include <string>
#include <vector>

#include "../include/Token.hpp"
#include "../include/Lexer.hpp"


bool isOperator(wchar_t input) {
    if(input == L'+' || input == L'-' || input == L'*' || input == L'/')
        return true;
    return false;
}

bool isVar(wchar_t input) {
    if((( input >= L'А' && input <= L'я') || std::isalpha(input)  || std::isdigit(input) || input == L'_'))
        return true;
    return false;
}

bool isDataType(std::wstring input) {
    if(input == L"целое" || input ==  L"плав" || input == L"строка")
        return true;
    return false;
}


Lexer::Lexer(std::wstring code) {
    this->code = code;
}

std::vector<Token> Lexer::CodeAnalysis() {
    while(pos < code.length()) {
        if(std::isspace(code[pos])) {
            pos++;
            continue;
        }
        if(isOperator(code[pos])) {
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
        if ((code[pos]>= L'А' && code[pos] <= L'я') || std::isalpha(code[pos])) {
            std::wstring id;
            while((pos < code.length()) && isVar(code[pos])) {
                id+=code[pos];
                pos++;
            }
            if(isDataType(id)) {
                tokens.push_back(Token(TokenType::DATATYPE, id, pos-id.length()+1));
                continue;
            }
            tokens.push_back(Token(TokenType::VAR, id, pos - id.length()+1));
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
        std::cerr << "Unknown character: ";
        printf("%ud ",pos);
        tokens.push_back(Token(TokenType::UNKNOWN, std::wstring(1, code[pos]), pos));
        pos++;
    }

    tokens.push_back(Token(TokenType::END, L"", pos));
    return tokens;

}