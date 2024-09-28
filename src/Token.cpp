#include <string>

#include "../include/Token.hpp"

Token::Token(TokenType type, std::string value, int pos) {
    this->type = type;
    this->value = value;
    this->pos = pos;
}

std::string Token::TypetoString() {
    if(type == TokenType::DATATYPE) {
        return "DATATYPE";
    } else if(type == TokenType::NUMBER) {
        return "NUMBER";
    } else if(type == TokenType::VAR) {
        return "VAR";
    } else if(type == TokenType::ASSIGN) {
        return "ASSIGN";
    } else if(type == TokenType::OPERATOR) {
        return "OPERATOR";
    } else if(type == TokenType::LPAREN) {
        return "LPAREN";
    } else if(type == TokenType::RPAREN) {
        return "RPAREN";
    } else if(type == TokenType::LBRACKET) {
        return "LBRACKET";
    } else if(type == TokenType::RBRACKET) {
        return "RBRACKET";
    } else if(type == TokenType::LSBRACKET) {
        return "LSBRACKET";
    } else if(type == TokenType::RSBRACKET) {
        return "RSBRACKET";
    } else if(type == TokenType::COMMA) {
        return "COMMA";
    } else if(type == TokenType::SEMICOLON) {
        return "SEMICOLON";
    } else if(type == TokenType::DOT) {
        return "DOT";
    } else if(type == TokenType::UNKNOWN) {
        return "UNKNOWN";
    } else if(type == TokenType::END) {
        return "END";
    }
}