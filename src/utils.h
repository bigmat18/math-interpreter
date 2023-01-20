#include "tokenize.h"

#ifndef UTILS_H
#define UTILS_H

int GetTokenArrayLength(Token* array);

Token* ConcatArrayToken(Token* tokens, Token* elem);

char* ConcatArrayChar(char* number, char elem);

#endif
