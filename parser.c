// parser.c
#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

ASTNode* createASTNode(ASTNodeType type, char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL; // Memory allocation failed
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* parseExpression(Token** tokens) {
    // Implementation of expression parsing
}

void destroyAST(ASTNode* root) {
    if (root) {
        destroyAST(root->left);
        destroyAST(root->right);
        free(root->value);
        free(root);
    }
}
