/*
** EPITECH PROJECT, 2020
** check_buffer.c
** File description:
** check_buffer.c
*/

#include "../include/main.h"

void last_free(my_shell_t *shell)
{
    free(shell->my_env);
    for (int i = 0; shell->new_env[i]; i++) {
        free(shell->new_env[i]);
    }
    free(shell->my_env);
}

int check_buffer_and_exec_function(char *buffer, char *args[], \
my_shell_t *shell, char *env[])
{
    shell->return_status = 0;

    if (my_strcmp(buffer, "exit") == 0) {
        my_printf("exit\n");
        if (args[1] != NULL) {
            free(shell->my_env);
            exit(my_getnbr(args[1]));
        }
        free(shell->my_env);
        exit(0);
    }
    if (buffer[0] == 'c' && buffer[1] == 'd') {
        if (builtin_cd(args, shell, env) == 1) {
            shell->return_status = 1;
            return (1);
        }
        shell->return_status = 2;
        return (2);
    }
    return (0);
}