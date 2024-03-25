// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

// Token types
typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_ERROR
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char* value;
} Token;

// Function prototypes
Token* nextToken(char** input);
void destroyToken(Token* token);

#endif // LEXER_H
