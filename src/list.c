#include <stdio.h>
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

    node->data = data;
    node->next = NULL;

    return node;
}

void
push(struct list *l, void *data)
{
    if (!l) {
        fputs("The list is unallocated. Can't push\n", stderr);
        exit(1);
    }

    struct node *node = new_node(data);

    if (!l->head) {
        l->head = node;
        l->tail = node;
    } else {
        node->next = l->head;
        l->head = node;
    }
}

void *
pop(struct list *l)
{
    if (!l) {
        fputs("The list is unallocated. Can't pop.\n", stderr);
        exit(1);
    }

    if (!l->head) {
        fputs("Can't pop empty list\n", stderr);
        exit(1);
    }

    struct node *node = l->head;

    if (node->next) {
        l->head = node->next;
    } else {
        l->head = NULL;
        l->tail = NULL;
    }

    void *data = node->data;
    free(node);

    return data;
}

void
enqueue(struct list *l, void *data)
{
    if (!l) {
        fputs("The list is unallocated. Can't enqueue.\n", stderr);
        exit(1);
    }

    struct node *node = new_node(data);

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
    if (!l) {
        fputs("Can't free empty list\n", stderr);
        exit(1);
    }

    if (!l->head) {
        free(l);
        return;
    }

    struct node *node = l->head;
    struct node *tmp;
    
    while (node) {
        tmp = node->next;
        free(node);
        node = tmp;
    }

    free(l);
}
