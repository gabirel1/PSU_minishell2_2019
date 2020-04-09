/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *str)
{
    int dest_len = my_strlen(dest);
    int str_len = my_strlen(str);
    char *final = malloc(sizeof(char) * (dest_len + str_len + 3));
    int j = 0;

    for (int i = 0; dest[i]; i++) {
        final[j++] = dest[i];
    }

    for (int i = 0; str[i]; i++) {
        final[j++] = str[i];
    }

    final[j] = 0;
    return (final);
}