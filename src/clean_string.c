/*
** EPITECH PROJECT, 2020
** clean_string.c
** File description:
** clean_string.c
*/

#include "../include/main.h"

char *clean_string(char *str)
{
    char *cleaned = NULL;
    str[my_strlen(str)] = 0;

    cleaned = clean_buffer(str);
    free(str);

    return (cleaned);
}
