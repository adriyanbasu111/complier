// lexer.c
#include "lexer.h"
#include <stdlib.h>
#include <ctype.h>

Token* createToken(TokenType type, char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    if (token == NULL) {
        return NULL; // Memory allocation failed
    }
    token->type = type;
    token->value = value;
    return token;
}

Token* nextToken(char** input) {
    while (**input && isspace(**input)) {
        (*input)++;
    }
    if (**input == '\0') {
        return createToken(TOKEN_EOF, NULL);
    }
    switch (**input) {
        case '+':
            (*input)++;
            return createToken(TOKEN_PLUS, "+");
        case '-':
            (*input)++;
            return createToken(TOKEN_MINUS, "-");
        case '*':
            (*input)++;
            return createToken(TOKEN_MULTIPLY, "*");
        case '/':
            (*input)++;
            return createToken(TOKEN_DIVIDE, "/");
        case '(':
            (*input)++;
            return createToken(TOKEN_LPAREN, "(");
        case ')':
            (*input)++;
            return createToken(TOKEN_RPAREN, ")");
        default:
            if (isdigit(**input)) {
                char* start = *input;
                while (isdigit(**input)) {
                    (*input)++;
                }
                int len = *input - start;
                char* value = (char*)malloc(len + 1);
                if (value == NULL) {
                    return NULL; // Memory allocation failed
                }
                strncpy(value, start, len);
                value[len] = '\0';
                return createToken(TOKEN_NUMBER, value);
            } else {
                return createToken(TOKEN_ERROR, "Invalid character");
            }
    }
}

void destroyToken(Token* token) {
    if (token) {
        free(token->value);
        free(token);
    }
}
