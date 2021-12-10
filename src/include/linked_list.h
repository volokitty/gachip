#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
append(void *data);

#endif
