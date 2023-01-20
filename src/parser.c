#include "parser.h"
#include "tokenize.h"
#include <stdio.h>
#include <stdlib.h>

Token* LookHead(Token* tokens){
    return &tokens[0];
}

void Consume(Token* tokens, int* size){
    (*size)--;
    Token* result = malloc((*size)*sizeof(Token));
    for(int i=0; i < (*size); i++) result[i] = tokens[i+1];
    tokens = result;
}

Expression* Exp(Token* tokens, int* size){
    Expression* t1 = Term(tokens, size);
    Token* token = LookHead(tokens);
    switch (token->token){
        case TKN_OP:{
            Expression exp;
            Consume(tokens, size);
            if(token->value == '+'){
                exp.op = &(Operation){ADD, t1, Exp(tokens, size)};
                return &exp;
            }else if(token->value == '-') {
                exp.op = &(Operation){SUB, t1, Exp(tokens, size)};
                return &exp;
            }
        }
    }
}

Expression* Term(Token *tokens, int *size){
    Expression* f1 = Factor(tokens, size);
    Token* token = LookHead(tokens);
    switch (token->token){
        case TKN_OP:{
            Expression exp;
            Consume(tokens, size);
            if(token->value == '*'){
                exp.op = &(Operation){MUL, f1, Exp(tokens, size)};
                return &exp;
            }else if(token->value == '/') {
                exp.op = &(Operation){DIV, f1, Exp(tokens, size)};
                return &exp;
            }
        }
    }
}

Expression* Factor(Token *tokens, int *size){
    Token* token = LookHead(tokens);
    switch (token->token){
        case TKN_NUM:{
            Expression exp;
            Consume(tokens, size);
            exp.val = token->value;
            return &exp;
        }
        case TKN_LPAR: {
            Consume(tokens, size);
            Expression* exp = Exp(tokens, size);
            token = LookHead(tokens);
            switch(token->token){
                case TKN_RPAR: {
                    Consume(tokens, size);
                    return exp;
                }
            }

        }
    }
}

Expression* Parser(Token* tokens, int* size){
    Expression* ast = Exp(tokens, size);
    switch(LookHead(tokens)->token){
        case TKN_END: {
            return ast;
        }
    }
}
