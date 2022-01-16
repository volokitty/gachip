#include <stdlib.h>
#include <string.h>
#include "include/token.h"

struct token *
init_token(enum state type, char *value)
{
    struct token *token = malloc(sizeof(struct token));

    token->type = type;
    strcpy(token->value, value);

    return token;
}
