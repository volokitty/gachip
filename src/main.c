#include "include/token.h"
#include "include/list.h"
#include "include/token_list.h"

int
main(int argc, char **argv)
{
    struct list *tokens = init_list();
    
    token_list_push(tokens, ID, "smile");
    token_list_push(tokens, ID, "draw");
    token_list_push(tokens, NUMBER, "0");
    
    print_token_list(tokens);

    return 0;
}
