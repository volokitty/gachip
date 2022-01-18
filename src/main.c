#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "include/file.h"
#include "include/list.h"
#include "include/lexer.h"
#include "include/token.h"

int
main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "%s: no input file\n", argv[0]);
        exit(1);
    }

    char *fcodename = argv[1];

    FILE *fcode;
    fcode = fopen(fcodename, "r");
    
    if (!fcode) {
        perror(fcodename);
        exit(1);
    }

    char *code = read_file(fcode);

    fclose(fcode);

    struct list *tokens = lex(code);
    free(code);

    struct node *curr = tokens->head;
    while (curr) {
        printf("{ type: %d, value: \"%s\" }\n", ((struct token *) curr->data)->type, ((struct token *) curr->data)->value);
        curr = curr->next;
    }

    free(tokens);

    return 0;
}
