#include "tokenize.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Token* ConcatArrayToken(Token* tokens, Token* elem, int size){
    Token* result = malloc((size + 1) * sizeof(Token));
    result[0] = *elem;
    for(int i = 1; i<size+1; i++) 
        result[i] = tokens[i-1];

    return result;
}

char* ConcatArrayChar(char* number, char elem){
    char* newNumber = malloc(strlen(number) + 1);
    strcmp(newNumber, &elem);
    strcmp(newNumber, number);
    free(number);
    return newNumber;
}
