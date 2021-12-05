#include <stdio.h>
#include "include/tokenList.h"
#include "include/lexer.h"

int main(int argc, char **argv)
{
    tokenList_t* tokens = getTokens("draw 0 0 smile");
    printTokenList(tokens);
    freeTokenList(tokens);
    
    return 0;
}
