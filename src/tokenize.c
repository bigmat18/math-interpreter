#include "tokenize.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Token* TokenizeRec(char* string, int position, int stringLength){

    if(position == stringLength) {
        Token *result = malloc(sizeof(Token));
        result[0] = (Token){TKN_END, NULL};
        return result;
    }

    char character = string[position];
    Token *tokens = TokenizeRec(string, position + 1, stringLength);

    switch (character) {
        case ' ':                                               return tokens;
        case '(':                                               return ConcatArrayToken(tokens, &(Token){TKN_LPAR, NULL});
        case ')':                                               return ConcatArrayToken(tokens, &(Token){TKN_RPAR, NULL});
        case '+': case '-': case '*': case '/':                 return ConcatArrayToken(tokens, &(Token){TKN_OP, &character});
        
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': {
            int number;

            if(tokens[0].token == TKN_NUM) 
                number = (int)atoi(ConcatArrayChar((char*)tokens[0].value, character));
            else 
                number = (int)atoi(&character);

            return ConcatArrayToken(tokens, &(Token){TKN_NUM, &number});
        } 
        default: {
            break;
        }
    }
    return NULL;
}

void Tokenize(char* string, int lenght) {
    Token* tokens= TokenizeRec(string, 0, lenght);
    for(int i=0; i<GetTokenArrayLength(tokens); i++){
        switch(tokens[i].token){
            case TKN_END: printf("TKN_END");
            case TKN_LPAR: printf("TKN_END");
            case TKN_RPAR: printf("TKN_END");
            case TKN_NUM: printf("TKN_END");
            case TKN_OP: printf("TKN_END");
        }
    }
}
