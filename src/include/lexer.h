#ifndef LEXER_H
#define LEXER_H

const char *operators = "+-*/";

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

void
lex(const char *code);

#endif
