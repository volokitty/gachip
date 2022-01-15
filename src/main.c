#include "include/list.h"
#include "include/lexer.h"

int
main(int argc, char **argv)
{
    lex("33       \n  \t \v\f+7a7 *(8 / 4) -3");

    return 0;
}
