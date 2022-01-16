#include <stdlib.h>
#include "include/list.h"

struct list *
init_list()
{
    struct list *l = malloc(sizeof(struct list));
    
    if (!l)
        exit(1);
    
    return l;
}

struct node *
new_node(void *data)
{
    struct node *node = malloc(sizeof(struct node));

    if (!node)
        exit(1);

    node->date = data;

    return node;
}

void
free_list(struct list *l)
{
    if (!l || !l->head)
        exit(1);

    struct node *node = l->head;
    struct node *tmp;
    
    while (node) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}
