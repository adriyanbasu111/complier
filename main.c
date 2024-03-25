#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"

int evaluate(ASTNode* root) {
    if (root->type == NODE_NUMBER) {
        return atoi(root->value);
    } else {
        int left = evaluate(root->left);
        int right = evaluate(root->right);
        switch (*(root->value)) {
            case '+': return left + right;
            case '-': return left - right;
            case '*': return left * right;
            case '/': return left / right;
        }
    }
    return 0; // Error
}

int main() {
    char input[1000];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    // Tokenization
    char* inputPtr = input;
    Token* tokens[100];
    int tokenCount = 0;
    Token* token;
    while ((token = nextToken(&inputPtr))!= NULL && token->type!= TOKEN_EOF && tokenCount < 100) {
        tokens[tokenCount++] = token;
    }

    // Parsing
    ASTNode* root = parseExpression(tokens);

    // Evaluation
    if (root!= NULL) {
        int result = evaluate(root);
        printf("Result: %d\n", result);

        // Clean up
        destroyAST(root);
        return 0;
    }

    return 1;
}