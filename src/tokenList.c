#include <stdio.h>
#include <stdlib.h>
#include "headers/tokenList.h"

static node_t* createNode(char* type, char* argument)
{
	node_t* node = malloc(sizeof(node_t));
	node->token.type = type;
	node->token.argument = argument;
	
	return node;
}

tokenList_t* createTokenList()
{
	return malloc(sizeof(tokenList_t));
}

void pushToken(tokenList_t* list, char* type, char* argument)
{
	node_t* node = createNode(type, argument);
	
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
}

void freeTokenList(tokenList_t* list)
{
	node_t* currNode = list->head;
	node_t* tmpNode;
	
	while (currNode->next)
	{
		tmpNode = currNode->next;
		free(currNode);
		currNode = tmpNode;
	}
}

void printTokenList(tokenList_t* list)
{
	node_t* currNode = list->head;
	
	while (currNode)
	{
		printf("(\"%s\", \"%s\")\n", currNode->token.type, currNode->token.argument);
		currNode = currNode->next;
	}
}
