#ifndef LEXER_H
#define LEXER_H

const char *ops;

enum state {
    INIT,
    WHITESPACE,
    DIGIT,
    NUMBER,
    LPAR,
    RPAR,
    OP,
    UNKNOWN
};

struct lexer {
    enum state state;
    enum state next_state;
    const char *code;
    char token[24];
};

struct list *
lex(const char *code);

#endif
