#include "headers/tokenList.h"

int main(int argc, char **argv)
{
    tokenList_t* tokens = createTokenList();
    
    pushToken(tokens, "number", "0x0");
    pushToken(tokens, "comma", "");
    pushToken(tokens, "number", "0x28");
    
    printTokenList(tokens);
    freeTokenList(tokens);

    return 0;
}
