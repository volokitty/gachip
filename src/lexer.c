#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "include/tokenList.h"
#include "include/lexer.h"
#include "include/token.h"

state_t getState(state_t prev, char c, unsigned int sourcePos)
{
    switch (prev)
    {
        case IDLE_STATE:
            if (isalpha(c))
                return 100;
            if (c == '[')
                return LBRACK;
            if (c == ']')
                return RBRACK;
            if (isdigit(c))
                return 500;
            if (c == ',')
                return COMMA;
            if (strchr("+-*/", c))
                return BINOP;
        case 100:
            if (isalpha(c) || isdigit(c))
                return 100;
            return ID;
        case 500:
            if (isdigit(c))
                return 500;
            return NUMBER;
        default:
            printf("Error. Unknown lexem on :%d\n", sourcePos);
            exit(1);
    }
}

tokenList_t* getTokens(char* source)
{
    tokenList_t* tokens = initTokenList();
    state_t state = IDLE_STATE;
    unsigned int sourcePos = 0;
    char token[20] = "";

    while (sourcePos <= strlen(source))
    {        
        state = getState(state, source[sourcePos], sourcePos);
        printf("state: %d\n", state);
       
        if (state < 100 || sourcePos == strlen(source))
        {
            pushToken(tokens, state, token);
            printf("%s\n", token);
            strcpy(token, "");
            state = IDLE_STATE;
        }
       
        if (!strchr(" \n\t", source[sourcePos]))
            strncat(token, &source[sourcePos], 1);
        
        sourcePos++;
    }

    return tokens;
}
