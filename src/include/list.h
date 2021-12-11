#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

struct node {
    struct node *next;
    void *data;
};

struct list {
    struct node *head;
    struct node *tail;
};

struct list *
init_list();

void
push(struct list *l, void *data, size_t size);

#endif
