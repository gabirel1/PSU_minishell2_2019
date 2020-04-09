/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *str)
{
    int i = 0;
    char *copy = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (; str[i]; i++) {
        copy[i] = str[i];
    }
    copy[i] = 0;
    return (copy);
}