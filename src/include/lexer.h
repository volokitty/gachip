#ifndef LEXER_H
#define LEXER_H

#include "tokenList.h"

#define IDLE_STATE 65535

typedef unsigned short state_t;

state_t getState(state_t prev, char c, unsigned int sourcePos);
tokenList_t* getTokens(char* source);

#endif
