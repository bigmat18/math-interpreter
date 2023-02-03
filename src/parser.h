#include "tokenize.h"

#ifndef PARSER_H
#define PARSER_H

Token* LookHead(Token* tokens, int* pos);

void Consume(int** pos);

Expression* Exp(Token** tokens, int* pos);

Expression* Term(Token** tokens, int* pos);

Expression* Factor(Token** tokens, int* pos);

Expression* Parser(char* string, int lenght);

#endif
