#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"

const char *ops = "+-*/";

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
            if (strchr(ops, c))
                return OP;
            if (c == '(')
                return LPAR;
            if (c == ')')
                return RPAR;
            else
                return UNKNOWN;
        case WHITESPACE:
            return INIT;
        case OP:
            return INIT;
        case DIGIT:
            if (isdigit(c))
                return DIGIT;
            return NUMBER;
        case LPAR:
            return INIT;
        case RPAR:
            return INIT;
        case NUMBER:
            return INIT;
        default:
            return UNKNOWN;
    }
}

static char
isunknwn(enum state state)
{
    if (state == UNKNOWN)
        return 1;
    return 0;
}

void
lex(const char *code)
{
    struct lexer *lexer = init_lexer(code);
    unsigned int i = 0;
    unsigned int line = 1;
    unsigned int last_line_i = 0;

    while (i < strlen(lexer->code)) {
        lexer->next_state = get_next_state(lexer->state, code[i]);

        if (isunknwn(lexer->next_state)) {
            fprintf(stderr, "Error: unknown character at %d:%d\n", line, i - last_line_i + 1);
            exit(1);
        }

        if (lexer->state && lexer->state != lexer->next_state) {
            if (strcmp(lexer->token, "") && lexer->state != WHITESPACE)
                puts(lexer->token);
            strcpy(lexer->token, "");
        } else {
            if (code[i] == '\n') {
                line++;
                last_line_i = i;
            }

            strncat(lexer->token, code + i, 1);
            i++;
        }

        lexer->state = lexer->next_state;
    }
    puts(lexer->token);

    free(lexer);
}
