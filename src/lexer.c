#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "headers/tokenList.h"
#include "headers/lexer.h"

state_t getState(state_t prev, char c)
{
    switch (prev)
    {
        case 0:
            if (isalpha(c))
                return 1;
            if (c == '[')
                return 3;
            if (c == ']')
                return 4;
            if (isdigit(c))
                return 5;
            if (c == ',')
                return 7;
            if (strchr(c, "+-*/"))
                return 8;
        case 1:
            if (isalpha(c) || isdigit(c))
                return 1;
            return 2;
        case 5:
            if (isdigit(c))
                return 5;
            return 6;
        default:
            printf("Error. Unknown lexem on %d\n", c);
            exit(1);
    }
}

tokenList_t* getTokens(char* source)
{
    tokenList_t* tokens = initTokenList();
    state_t state = 0;
    unsigned int sourcePos = 0;

    while (source[sourcePos] != '\0')
    {
        state = getState(state, c);
    }

    return tokens;
}
