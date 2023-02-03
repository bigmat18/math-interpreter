#pragma once

#ifndef TOKENIZE_H
#define TOKENIZE_H

struct Expression;
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
    struct Expression* leftExp;
    struct Expression* rightExp;
};

struct Expression {
    int val;
    struct Operation* op;
};

struct Token {
    enum TokenType token;
    char* value;
};

typedef struct Expression Expression;
typedef struct Operation Operation;
typedef enum Operator Operator;
typedef enum TokenType TokenType;
typedef struct Token Token;

Token* TokenizeRec(char *string, int position, int stringLenght, int* size);
Token *Tokenize(char *string, int lenght, int *size);

#endif
