#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"
#include "include/list.h"
#include "include/token.h"

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

struct list *
lex(const char *code)
{
    struct lexer *lexer = init_lexer(code);
    struct list *tokens = init_list();
    
    size_t code_len = strlen(code);
    size_t pos = 0;
    size_t line = 1;
    size_t last_line_pos = 0;

    while (pos < code_len || lexer->next_state == UNKNOWN) {
        lexer->next_state = get_next_state(lexer->state, code[pos]);

        if (lexer->next_state == INIT) {
            if (lexer->state != WHITESPACE) {
                struct token *token = init_token(lexer->state, lexer->token);
                enqueue(tokens, token);
            }

            strcpy(lexer->token, "");
        }

        if (lexer->state == INIT || lexer->state == lexer->next_state) {
            strncat(lexer->token, code + pos++, 1);
        }

        lexer->state = lexer->next_state;
    }

    if (lexer->next_state == UNKNOWN) {
        fprintf(stderr, "Error: unknown character at %ld:%ld\n", line, pos - last_line_pos + 1);
        exit(1);
    }

    free(lexer);

    return tokens;
}
