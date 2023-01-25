#include "tokenize.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Token* TokenizeRec(char* string, int position, int stringLength, int* size){

    if(position == stringLength) {
        Token *result = malloc(sizeof(Token));
        result[0] = (Token){TKN_END, NULL};
        (*size)++;
        return result;
    }

    char character = string[position];
    Token *tokens = TokenizeRec(string, position + 1, stringLength, size);

    (*size)++;
    switch (character) {
        case ' ':                                               (*size)--; return tokens;
        case '(':                                               return ConcatArrayToken(tokens, &(Token){TKN_LPAR, NULL}, *size);
        case ')':                                               return ConcatArrayToken(tokens, &(Token){TKN_RPAR, NULL}, *size);
        case '+': case '-': case '*': case '/': {
            char* operation = malloc(sizeof(char));
            operation[0] = character;
            return ConcatArrayToken(tokens, &(Token){TKN_OP, operation}, *size);
        }
        
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
            char* number = NULL;

            if(tokens[0].token == TKN_NUM){
                (*size)--;
                tokens[0].value = ConcatArrayChar(tokens[0].value, &character);
                return tokens;
            } else {
                number = malloc(sizeof(char)); number[0] = character;
                return ConcatArrayToken(tokens, &(Token){TKN_NUM, number}, *size);
            }
        } 
        default: (*size)--;
    }
    return NULL;
}

Token* Tokenize(char* string, int lenght, int* size) {
    Token* tokens = TokenizeRec(string, 0, lenght, size);
    for(int i=0; i<(*size); i++){
        switch(tokens[i].token){
            case TKN_END: {
                printf("TKN_END ");
                break;
            }
            case TKN_LPAR: {
                printf("TKN_LPAR ");
                break;
            }
            case TKN_RPAR: {
                printf("TKN_RPAR ");
                break;
            }
            case TKN_NUM: {
                printf("TKN_NUM ");
                break;
            }
            case TKN_OP: {
                printf("TKN_OP ");
                break;
            }
        }
    }
    return tokens;
}
