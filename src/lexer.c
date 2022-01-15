#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"

static struct lexer *
init_lexer(const char *code)
{
    struct lexer *lexer = malloc(sizeof(struct lexer));

    lexer->state = START;
    lexer->code = code;
    lexer->token = "";

    return lexer;
}

static enum state
get_next_state(enum state state, char c)
{
    switch (state) {
        case START:
            if (isspace(c))
                return WHITESPACE;
            if (isdigit(c))
                return DIGIT;
            if (strchr(operators, c)
                return OP;
            if (c == '(')
                return LPAR;
            if (c == ')')
                return RPAR;
        case WHITESPACE:
            return START;
        case OP:
            return OP;
        case LPAR:
            return START;
        case RPAR:
            return START;
        case DIGIT:
            if (isdigit)
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

    unsigned int = 0;
    while (i < strlen(lexer->code)) {
        lexer->next_state = get_next_state(lexer->state, code[i]);

        if (lexer->next_state == START) {
            if (lexer->state != WHITESPACE) {
                puts(lexer->token);
                lexer->token = "";
                i--;
            }
        }
    }

    free(lexer);
}
