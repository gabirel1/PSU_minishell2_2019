/*
** EPITECH PROJECT, 2020
** parse_env.c
** File description:
** parse_env.c
*/

#include "../include/main.h"

void parse_env(char *env[], my_shell_t *shell)
{
    int i = 0;

    while (env[i] != NULL && (env[i][0] != 'P' || env[i][1] != 'A' \
    || env[i][2] != 'T' || env[i][3] != 'H' || env[i][4] != '=')) {
        i += 1;
    }
    shell->env_paths = env[i];
}

char *get_path(my_shell_t *shell, char **args)
{
    char *tmp = my_strcat("/", args[0]);
    char *str = NULL;
    char *string = NULL;
    int i = 0;

    while (shell->my_env[i] != NULL) {
        string = my_strcat(shell->my_env[i], tmp);
        if (access(string, X_OK) == 0) {
            str = my_strcat(shell->my_env[i], tmp);
            free(string);
            free(tmp);
            return (str);
        }
        free(string);
        i += 1;
    }
    free(tmp);
    return (args[0]);
}

void parsing(my_shell_t *shell, char *env[])
{
    parse_env(env, shell);
    shell->my_env = my_str_to_word_array(&shell->env_paths[5], ':');
}