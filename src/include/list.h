#ifndef LIST_H
#define LIST_H

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
append(struct list *l, void *data);

#endif
