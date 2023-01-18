#include "tokenize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Token* ConcatArrayToken(Token* tokens, Token* elem){
    size_t tokensLength = sizeof(tokens) / sizeof(tokens[0]);
    Token* result = malloc(tokensLength * sizeof(Token));
    memcpy(result, elem, sizeof(Token));
    memcpy(result + 1, tokens, tokensLength * sizeof(Token));
    return result;
}

char* ConcatArrayChar(char* number, char elem){
    char* newNumber = malloc(strlen(number) + 1);
    strcmp(newNumber, elem);
    strcmp(newNumber, number);
    return newNumber;
}


Token* TokenizeRec(char* string[], int position, int stringLenght){
    if(position == stringLenght) {
        Token *result = malloc(sizeof(Token));
        result[0] = (Token){TKN_END, NULL};
        return result;
    }else{
        char charachter = string[position];
        Token *tokens = TokenizeRec(string, position + 1, stringLenght);
        switch (charachter) {
            case ' ': return tokens;
            case '(': return ConcatArrayToken(tokens, &(Token){TKN_LPAR, NULL});
            case ')': return ConcatArrayToken(tokens, &(Token){TKN_RPAR, NULL});
            case '+': case '-': case '*': case '/': 
                return ConcatArrayToken(tokens, &(Token){TKN_OP, &charachter});
            case '0': case '1': case '2': case '3': case '4': 
            case '5': case '6': case '7': case '8': case '9': {
                if(tokens[0].token == TKN_NUM) return ConcatArrayToken(tokens, &(Token){TKN_NUM, (int)atoi(ConcatArrayChar((char*)tokens[0].value, charachter))});
                else return ConcatArrayToken(tokens, &(Token){TKN_NUM, (int)atoi(charachter)});
            } 
            default: {
                break;
            }
        }
    }
}

void Tokenize(char* string[], int lenght) {
    TokenizeRec(string, 0, lenght);
}