#include "eval.h"
#include "tokenize.h"
#include <stdio.h>

int Eval(Expression* exp){
    if(exp->op == NULL){
        return exp->val;
    } 

    switch (exp->op->op) {
        case ADD: {
            return Eval(exp->op->leftExp) + Eval(exp->op->rightExp);
        }
        case SUB: {
            return Eval(exp->op->leftExp) - Eval(exp->op->rightExp);
        }
        case MUL: {
            return Eval(exp->op->leftExp) * Eval(exp->op->rightExp);
        }
        case DIV: {
            return Eval(exp->op->leftExp) / Eval(exp->op->rightExp);
        }
    }
}
