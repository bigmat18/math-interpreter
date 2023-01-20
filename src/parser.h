#ifndef PARSER_H
#define PARSER_H

Token* LookHead(Token* tokens);

void Consume(Token* tokens, int size);

void Exp();

void Term();

void Factor();

#endif