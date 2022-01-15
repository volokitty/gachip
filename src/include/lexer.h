#ifndef LEXER_H
#define LEXER_H

enum states {
    START,
    WHITESPACE,
    DIGIT,
    NUMBER,
    LPAR,
    RPAR,
    OP,
    UNKNOWN
};

char is_whitespace(char c);


#endif
