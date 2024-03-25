// parser.h
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// AST node types
typedef enum {
    NODE_NUMBER,
    NODE_BINARY_OP
} ASTNodeType;

// AST node structure
typedef struct ASTNode {
    ASTNodeType type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

// Function prototypes
ASTNode* parseExpression(Token** tokens);
void destroyAST(ASTNode* root);

#endif // PARSER_H
