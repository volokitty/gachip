#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include "list.h"
#include "token.h"

void
token_list_push(struct list *l, enum token_type type, char *arg);

void
print_token_list(struct list *l);

void
free_token_list(struct list *l);

#endif
