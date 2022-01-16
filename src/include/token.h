#ifndef TOKEN_H
#define TOKEN_H

#include "lexer.h"

struct token {
    enum state type;
    char value[24];
};

struct token *
init_token(enum state type, char *value);

#endif
