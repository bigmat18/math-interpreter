#include "tokenize.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetTokenArrayLength(Token* array){
    return (int)sizeof(array) / (int)sizeof(array[0]);
}

Token* ConcatArrayToken(Token* tokens, Token* elem){
    int tokensLength = GetTokenArrayLength(tokens);
    Token* result = malloc(tokensLength * sizeof(Token));
    memcpy(result, elem, sizeof(Token));
    memcpy(result + 1, tokens, tokensLength * sizeof(Token));
    return result;
}

char* ConcatArrayChar(char* number, char elem){
    char* newNumber = malloc(strlen(number) + 1);
    strcmp(newNumber, &elem);
    strcmp(newNumber, number);
    return newNumber;
}
