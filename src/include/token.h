#ifndef TOKEN_H
#define TOKEN_H

enum token_type {
    ID,
    BINOP,
    LBRACK,
    RBRACK,
    NUMBER,
    COMMA
};

struct token {
    enum token_type type;
    char *arg;
};

#endif
