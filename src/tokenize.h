#pragma once

#ifndef TOKENIZE_H
#define TOKENIZE_H

union Expression;
struct Operation;

enum Operator {
    ADD,
    SUB,
    MUL,
    DIV
};

enum TokenType {
    TKN_NUM,
    TKN_OP,
    TKN_LPAR,
    TKN_RPAR,
    TKN_END
};

struct Operation {
    enum Operator op;
    union Expression* leftExp;
    union Expression* rightExp;
};

union Expression {
    int val;
    struct Operation* op;
};

struct Token {
    enum TokenType token;
    void* value;
};

typedef union Expression Expression;
typedef struct Operation Operation;
typedef enum Operator Operator;
typedef enum TokenType TokenType;
typedef struct Token Token;

Token* TokenizeRec(char *string, int position, int stringLenght, int* size);
Token* Tokenize(char *string, int lenght);

#endif
