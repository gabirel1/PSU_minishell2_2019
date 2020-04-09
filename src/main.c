/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../include/main.h"

int malloc_my_cd(my_shell_t *shell)
{
    shell->old_cd = malloc(sizeof(char) * 500);

    if (shell->old_cd == NULL) {
        return (1);
    } else {
        shell->old_cd[0] = 0;
    }

    return (0);
}

int main(int ac, char *av[], char *env[])
{
    (void)av;
    my_shell_t shell;

    if (malloc_my_cd(&shell) == 1)
        return (84);
    save_streams(&shell);

    if (ac >= 2) {
        write(1, "error\n", 6);
        return (84);
    } else {
        shell.new_env = return_tab(env);
        if (shell.new_env == NULL)
            return (84);
        init_shell(env, &shell);
        return (0);
    }
}