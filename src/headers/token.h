#ifndef TOKEN_H
#define TOKEN_H

enum tokenType
{
    ID,
    EQUALS,
    LBRACK,
    RBRACK,
    NUMBER,
    COMMA
};

typedef struct TOKEN_STRUCT
{
    enum tokenType type;
    char* value;
} token_t;

#endif
