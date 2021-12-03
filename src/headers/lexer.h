#ifndef LEXER_H
#define LEXER_H

#include "tokenList.h"

typedef unsigned char state_t;

state_t getState(state_t prev, char c);
tokenList_t* getTokens(char* source);

#endif
