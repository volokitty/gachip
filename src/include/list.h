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

struct node *
new_node(void *data);

void
push(struct list *l, void *data);

void *
pop(struct list *l);

void
enqueue(struct list *l, void *data);

void *
dequeue(struct list *l);

void
free_list(struct list *l);

#endif
