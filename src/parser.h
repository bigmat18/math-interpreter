#include "tokenize.h"

#ifndef PARSER_H
#define PARSER_H

Token* LookHead(Token* tokens, int* pos);

void Consume(int** pos);

Operation* CreateOperation(Operator op, Expression* leftExp, Expression* rightExp);

Expression* Exp(Token** tokens, int* pos);

Expression* Term(Token** tokens, int* pos);

Expression* Factor(Token** tokens, int* pos);

Expression* Parser(char* string, int lenght);

#endif
