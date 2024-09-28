#include <iostream>
#include <string>
#include <vector>

#include "../include/Token.hpp"
#include "../include/Lexer.hpp"


Lexer::Lexer(std::string code) {
    this->code = code;
}

std::vector<Token> Lexer::CodeAnalysis() {
    while(pos < code.length()) {
    char c = code[pos];
    if(std::isspace(c)) {
        pos++;
        continue;
    }
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        tokens.push_back(Token(TokenType::OPERATOR, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == '=') {
        tokens.push_back(Token(TokenType::ASSIGN, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == ')') {
        tokens.push_back(Token(TokenType::RPAREN, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == '(') {
        tokens.push_back(Token(TokenType::LPAREN, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == '[') {
        tokens.push_back(Token(TokenType::LSBRACKET, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == ']') {
        tokens.push_back(Token(TokenType::RSBRACKET, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == '[') {
        tokens.push_back(Token(TokenType::LBRACKET, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == ']') {
        tokens.push_back(Token(TokenType::RBRACKET, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == ',') {
        tokens.push_back(Token(TokenType::COMMA, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == '.') {
        tokens.push_back(Token(TokenType::DOT, std::string(1, c), pos));
        pos++;
        continue;
    }
    if(c == ';') {
        tokens.push_back(Token(TokenType::SEMICOLON, std::string(1, c), pos));
        pos++;
        continue;
    }
    if (std::isalpha(c)) {
        std::string id;
        while(pos < code.length() && (std::isalnum(code[pos]) || code[pos] == '_')) {
            id+=code[pos];
            pos++;
        }
        if(id == "int" || id == "float" || id == "string") {
            tokens.push_back(Token(TokenType::DATATYPE, id, pos-id.length()));
            continue;
        }
        tokens.push_back(Token(TokenType::VAR, id, pos - id.length()));
        continue;
    }
    if(std::isdigit(c)) {
        std::string num;
        while(pos < code.length() && std::isdigit(code[pos])) {
            num+=code[pos];
            pos++;
        }
        tokens.push_back(Token(TokenType::NUMBER, num, pos));
        continue;
    }
    std::cerr << "Unknown character: " << c <<"Position: " << pos <<  std::endl;
    tokens.push_back(Token(TokenType::UNKNOWN, std::string(1, c), pos++));
}

tokens.push_back(Token(TokenType::END, "", pos));
return tokens;
}
