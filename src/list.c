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
push(struct list *l, void *data)
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

void
free_list(struct list *l)
{
    if (!l || !l->head) exit(1);

    struct node *node = l->head;
    struct node *tmp;
    
    while (node) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}
