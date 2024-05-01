#include "minishell.h"



int main(int ac, char*av[], char *env[])
{
    (void)ac;
    (void)av;
    (void)env;
    t_gc *gc = NULL;
    char    *cmd;
    do 
    {
        cmd = readline(" > ");
        gc_push(&gc, cmd);
        printf("cmd: %s\n", cmd);
    }
    while (cmd);
    gc_clear(&gc);
}