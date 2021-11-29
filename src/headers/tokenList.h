#ifndef __TOKENS_LIST_H_
#define __TOKENS_LIST_H_

typedef struct
{
    char* type;
    char* argument;
} token_t;

typedef struct node
{
    struct node* next;
    token_t token;
} node_t;

typedef struct
{
    node_t* head;
    node_t* tail;
} tokenList_t;

tokenList_t* createTokenList();

void pushToken(tokenList_t* list, char* type, char* argument);
void freeTokenList(tokenList_t* list);
void printTokenList(tokenList_t* list);

#endif
