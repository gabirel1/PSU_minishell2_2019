/*
** EPITECH PROJECT, 2020
** clean_buffer.c
** File description:
** clean_buffer.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

char *clean_buffer(char *str)
{
    int i = 0;
    int j = 0;
    char *final = malloc(sizeof(char) * (my_strlen(str) + 2));

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    while (str[i + 1] != 0) {
        if ((str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\t')) \
        || (str[i] == '\t' && (str[i + 1] == '\t' || str[i + 1] == ' '))) {
        } else if ((str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\t') \
        || (str[i] == '\t' && str[i + 1] != '\t' && str[i + 1] != ' ')) {
            final[j++] = ' ';
        } else
            final[j++] = str[i];
        i++;
    }
    if (str[i - 1] == ' ' || str[i - 1] == '\t')
        final[j - 1] = 0;
    else
        final[j] = 0;
    return (final);
}