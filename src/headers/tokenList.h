#ifndef TOKENS_LIST_H
#define TOKENS_LIST_H

typedef struct TOKEN_STRUCT
{
    char* type;
    char* value;
} token_t;

typedef struct NODE_STRUCT
{
    struct NODE_STRUCT* next;
    token_t token;
} node_t;

typedef struct TOKEN_LIST_STRUCT
{
    node_t* head;
    node_t* tail;
} tokenList_t;

tokenList_t* createTokenList();

void pushToken(tokenList_t* list, char* type, char* argument);
void freeTokenList(tokenList_t* list);
void printTokenList(tokenList_t* list);

#endif
