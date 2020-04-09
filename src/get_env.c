/*
** EPITECH PROJECT, 2020
** get_env.c
** File description:
** get_env.c
*/

#include "../include/main.h"

int get_env_size(char *env[])
{
    int size = 0;

    if (env == NULL)
        return (0);
    for (int i = 0; env[i] != NULL; i++) {
        size++;
    }
    return (size);
}

char *cpy_line(char *str)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (tmp == NULL)
        return (NULL);

    for (; str[i]; i++) {
        tmp[i] = str[i];
    }
    tmp[i] = 0;

    return (tmp);
}

char **return_tab(char *tab[])
{
    int size = get_env_size(tab);
    char **my_env = NULL;
    int i = 0;

    if (size == 0)
        return (NULL);
    my_env = malloc(sizeof(char *) * (size + 1));
    if (my_env == NULL)
        return (NULL);

    for (; tab[i]; i++) {
        my_env[i] = cpy_line(tab[i]);
        if (my_env[i] == NULL)
            return (NULL);
    }
    my_env[i] = NULL;
    return (my_env);
}