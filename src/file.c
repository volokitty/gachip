#include <stdio.h>
#include <stdlib.h>
#include "include/file.h"

char *
read_file(FILE *fp)
{
    fseek(fp, 0L, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    char *s = malloc(size);
    size_t i = 0;

    while ((s[i++] = fgetc(fp)) != EOF) {}
    s[--i] = 0;

    return s;
}
