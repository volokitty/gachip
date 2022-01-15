#ifndef LEXER_H
#define LEXER_H

const char *operators = "+-*/";

enum states {
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
    enum state;
    enum next_state;
    char *code;
    char token[24];
};

void
lex(struct lexer *lexer)

#endif
