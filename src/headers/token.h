#ifndef TOKEN_H
#define TOKEN_H

enum tokenType
{
    ID,
    LBRACK,
    RBRACK,
    NUMBER,
    COMMA,
    BINOP,
    UNOP
};

typedef struct TOKEN_STRUCT
{
    enum tokenType type;
    char* value;
} token_t;

#endif
