#include "include/lexer.h"

char is_whitespace(char c)
{
    return c == '\t' || c == '\n' || c == '\r' || c == ' ';
}

