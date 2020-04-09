/*
** EPITECH PROJECT, 2020
** print_exec_error.c
** File description:
** print_exec_error.c
*/

#include "../include/main.h"

void print_exec_error(char *args[], char *path_final)
{
    if (errno == ENOEXEC) {
        my_putstr(args[0]);
        my_printf(": Exec format error. Wrong Architecture.\n");
    } else if (access(path_final, X_OK) != 0) {
        my_putstr(args[0]);
        my_printf(": Command not found.\n");
    } else {
        my_putstr(args[0]);
        my_printf(": ");
        my_putstr(strerror(errno));
        my_printf(".\n");
    }
    exit (0);
}