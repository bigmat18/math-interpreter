#include "parser.h"
#include "tokenize.h"
#include <stdio.h>
#include <stdlib.h>


Token* LookHead(Token* tokens, int *pos){return &tokens[*pos];}

void Consume(int** pos){(**pos)++;}

Expression* Exp(Token** tokens, int* pos){
    Expression* t1 = Term(tokens, pos);
    Token* token = LookHead(*tokens, pos);

    switch(token->token) {
        case TKN_OP: {
            switch (*(token->value)){
                case '+': {
                    Expression* exp = (Expression*)malloc(sizeof(Expression));
                    Consume(&pos);
                    exp->op = &(Operation){ADD, t1, Exp(tokens, pos)};
                    return exp;
                }
                case '-': {
                    Expression *exp = (Expression*)malloc(sizeof(Expression));
                    Consume(&pos);
                    exp->op = &(Operation){SUB, t1, Exp(tokens, pos)};
                    return exp;
                }
                default:
                    return t1;
            }
        }
        default:
            return t1;
    }
    return NULL;
}

Expression* Term(Token** tokens, int *pos){
    Expression* f1 = Factor(tokens, pos);
    Token* token = LookHead(*tokens, pos);

    switch (token->token){
        case TKN_OP: {
            switch(*(token->value)){
                case '*': {
                    Expression *exp = (Expression*)malloc(sizeof(Expression));
                    Consume(&pos);
                    exp->op = &(Operation){MUL, f1, Exp(tokens, pos)};
                    return exp;
                }
                case '/': {
                    Expression *exp = (Expression*)malloc(sizeof(Expression));
                    Consume(&pos);
                    exp->op = &(Operation){DIV, f1, Exp(tokens, pos)};
                    return exp;
                }
                default:
                    return f1;
            }
        }
        default:
            return f1;
    }
    return NULL;
}

Expression* Factor(Token** tokens, int *pos){
    Token* token = LookHead(*tokens, pos);

    switch (token->token){
        case TKN_NUM:{
            Expression* exp = (Expression*)malloc(sizeof(Expression));
            Consume(&pos);
            exp->op = NULL;
            exp->val = atoi(token->value);
            return exp;
        }
        case TKN_LPAR: {
            Consume(&pos);
            Expression* exp = Exp(tokens, pos);
            token = LookHead(*tokens, pos);

            switch(token->token){
                case TKN_RPAR: {
                    Consume(&pos);
                    return exp;
                }
                default:
                    break;
            }
        }
        default:
            break;
    }
    return NULL;
}

Expression* Parser(char* string, int lenght){
    int size = 0, pos = 0;
    Token* tokens = Tokenize(string, lenght, &size);
    Expression* ast = Exp(&tokens, &pos);

    switch(LookHead(tokens, &pos)->token){
        case TKN_END: {
            return ast;
        }
        default:
            break;
    }
    return NULL;
}
