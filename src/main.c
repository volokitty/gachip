#include <stdio.h>
#include <string.h>
#include "headers/token.h"
#include "headers/tokenList.h"

int main(int argc, char **argv)
{
    tokenList_t* tokens = initTokenList();
    
    pushToken(tokens, NUMBER, "0x0");
    pushToken(tokens, ID, "smile");
    pushToken(tokens, NUMBER, "0x28");
    
    printTokenList(tokens);
    freeTokenList(tokens);

    return 0;
}
