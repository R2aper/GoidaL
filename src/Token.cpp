#include <string>

#include "../include/Token.hpp"

Token::Token(TokenType type, std::wstring value, int pos) {
    this->type = type;
    this->value = value;
    this->pos = pos;
}

std::wstring Token::TypetoWstring() {
    if(type == TokenType::DATATYPE) {
        return L"DATATYPE";
    } else if(type == TokenType::NUMBER) {
        return L"NUMBER";
    } else if(type == TokenType::VAR) {
        return L"VAR";
    } else if(type == TokenType::ASSIGN) {
        return L"ASSIGN";
    } else if(type == TokenType::OPERATOR) {
        return L"OPERATOR";
    } else if(type == TokenType::LPAREN) {
        return L"LPAREN";
    } else if(type == TokenType::RPAREN) {
        return L"RPAREN";
    } else if(type == TokenType::LBRACKET) {
        return L"LBRACKET";
    } else if(type == TokenType::RBRACKET) {
        return L"RBRACKET";
    } else if(type == TokenType::LSBRACKET) {
        return L"LSBRACKET";
    } else if(type == TokenType::RSBRACKET) {
        return L"RSBRACKET";
    } else if(type == TokenType::COMMA) {
        return L"COMMA";
    } else if(type == TokenType::SEMICOLON) {
        return L"SEMICOLON";
    } else if(type == TokenType::DOT) {
        return L"DOT";
    } else if(type == TokenType::UNKNOWN) {
        return L"UNKNOWN";
    } else if(type == TokenType::END) {
        return L"END";
    }
}