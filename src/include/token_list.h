#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include "linked_list.h"

typedef struct list token_list;

token_list *
init_token_list();

void
token_list_append(token_list *l, struct token t);

void
show_token_list(token_list *l);

#endif
