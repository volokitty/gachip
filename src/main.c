#include "include/list.h"
#include "include/lexer.h"

int
main(int argc, char **argv)
{
    lex("33 + 7*(8 / 4) - 3");

    return 0;
}
