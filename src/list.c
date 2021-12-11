#include <stdlib.h>
#include "include/list.h"

struct list *
init_list()
{
    struct list *l = malloc(sizeof(struct list));
    
    if (!l) exit(1);
    
    return l;
}

void
append(struct list *l, void *data)
{
    struct node *node = malloc(sizeof(node));
    
    if (!node) exit(1);
    
    node->data = data;

    if (!l->head) {
        l->head = node;
        l->tail = node;
    } else {
        l->tail->next = node;
        l->tail = node;
    }
}
