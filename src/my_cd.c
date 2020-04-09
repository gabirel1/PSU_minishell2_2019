/*
** EPITECH PROJECT, 2020
** my_cd.c
** File description:
** my_cd.c
*/

#include "../include/main.h"

int builtin_cd_less(my_shell_t *shell)
{
    char *buffer = NULL;
    size_t size = 0;
    char *save_path = getcwd(buffer, size);

    if (chdir(shell->old_cd) == -1) {
        my_printf(": ");
        my_putstr(strerror(errno));
        my_printf(".\n");
        return (1);
    }
    shell->old_cd = save_path;
    return (0);
}

int builin_cd_with_args(char *args[], my_shell_t *shell)
{
    char *buffer = NULL;
    size_t size = 0;
    shell->old_cd = getcwd(buffer, size);

    if (chdir(args[1]) == -1) {
        my_putstr(args[1]);
        my_printf(": ");
        if (errno == ENOTDIR) {
            my_printf("Not a directory.\n");
        } else if (errno == ENOENT) {
            my_printf("No such file or directory.\n");
        }
        return (1);
    }
    return (0);
}

void get_good_path(my_shell_t *shell, char *env[])
{
    int i = 0;
    int j = 0;
    int z = 0;

    while (env[i][0] != 'H' || env[i][1] != 'O' || env[i][2] != 'M' \
    || env[i][3] != 'E' || env[i][4] != '=') {
        i += 1;
    }
    shell->home_path = malloc(sizeof(char) * (my_strlen(env[i])));
    shell->home_path[0] = 0;
    for (j = 0; env[i][j] != '='; j++);
    j += 1;
    for (; env[i][j] != 0; j++, z++) {
        shell->home_path[z] = env[i][j];
    }
    shell->home_path[z] = 0;
}

int builtin_cd_no_args(my_shell_t *shell, char *env[])
{
    char *buffer = NULL;
    size_t size = 0;

    get_good_path(shell, env);
    shell->old_cd = getcwd(buffer, size);

    if (chdir(shell->home_path) == -1) {
        my_putstr(strerror(errno));
        my_printf(".\n");
        return (1);
    }
    return (0);
}

int builtin_cd(char *args[], my_shell_t *shell, char *env[])
{
    if (args[1] == NULL) {
        if (builtin_cd_no_args(shell, env) == 1)
            return (1);
        return (0);
    } else if (args[1][0] == '-') {
        if (builtin_cd_less(shell) == 1)
            return (1);
        return (0);
    } else {
        if (builin_cd_with_args(args, shell) == 1)
            return (1);
        return (0);
    }
    return (0);
}