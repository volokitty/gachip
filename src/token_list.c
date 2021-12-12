#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"
#include "include/token_list.h"

void
token_list_push(struct list *l, enum token_type type, char *arg)
{
    struct token *t = malloc(sizeof(struct token));
    
    if (!t) exit(1);
    
    t->type = type;
    t->arg = arg;
    
    push(l, t);
}

void
print_token_list(struct list *l)
{
    if (!l || !l->head) exit(1);
    
    struct node *node = l->head;
    struct token *data;
    
    while (node) {
        data = node->data;
        printf("('%d', '%s')\n", data->type, data->arg);
        node = node->next;
    }
}
