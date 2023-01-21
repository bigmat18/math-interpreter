#include "tokenize.h"

#ifndef PARSER_H
#define PARSER_H

Token* LookHead(Token* tokens);

void Consume(Token** tokens, int* size);

Expression* Exp(Token* tokens, int* size);

Expression* Term(Token* tokens, int* size);

Expression* Factor(Token* tokens, int* size);

Expression* Parser(char* string, int lenght);

#endif
