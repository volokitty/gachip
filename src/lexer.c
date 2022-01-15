#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"

static struct lexer *
init_lexer(const char *code)
{
    struct lexer *lexer = malloc(sizeof(struct lexer));

    lexer->state = INIT;
    lexer->next_state = -1;
    lexer->code = code;
    strcpy(lexer->token, "");

    return lexer;
}

static enum state
get_next_state(enum state state, char c)
{
    switch (state) {
        case INIT:
            if (isspace(c))
                return WHITESPACE;
            if (isdigit(c))
                return DIGIT;
            if (strchr(operators, c))
                return OP;
            if (c == '(')
                return LPAR;
            if (c == ')')
                return RPAR;
        case WHITESPACE:
            return INIT;
        case OP:
            return INIT;
        case LPAR:
            return INIT;
        case RPAR:
            return INIT;
        case DIGIT:
            if (isdigit(c))
                return DIGIT;
            return NUMBER;
        default:
            return UNKNOWN;
    }
}

void
lex(const char *code)
{
    struct lexer *lexer = init_lexer(code);

    unsigned int i = 0;
    while (i < strlen(lexer->code)) {
        lexer->next_state = get_next_state(lexer->state, code[i]);

        if (lexer->next_state == INIT) {
            if (lexer->state != WHITESPACE) {
                puts(lexer->token);
            }

            strcpy(lexer->token, "");
            i--;
        } else {
            if (lexer->state != WHITESPACE) {
                strncat(lexer->token, code + i, 1);
            }

            lexer->state = lexer->next_state;
            i++;
        }
    }

    free(lexer);
}
