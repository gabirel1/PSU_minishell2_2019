/*
** EPITECH PROJECT, 2020
** my_saver.c
** File description:
** my_saver.c
*/

#include "../include/main.h"

void save_streams(my_shell_t *shell)
{
    shell->save.my_stdin = dup(0);
    shell->save.my_stdout = dup(1);
    shell->save.my_stderr = dup(2);
}

void reset_streams(my_shell_t *shell)
{
    dup2(shell->save.my_stdin, 0);
    dup2(shell->save.my_stdout, 1);
    dup2(shell->save.my_stderr, 2);
}

void writing_in_file(my_shell_t *shell, char *filename)
{
    int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR
    | S_IRGRP | S_IROTH);
    dup2(fd, 1);

    //following
}