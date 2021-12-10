#include <stdlib.h>
#include "include/list.h"

struct list *
init_list()
{
    return malloc(sizeof(struct list));
}

void
append(struct list *l, void *data)
{
    struct node *node = malloc(sizeof(node));
    node->data = data;

    if (!l->head) {
        l->head = node;
        l->tail = node;
    } else {
        l->tail->next = node;
        l->tail = node;
    }
}
