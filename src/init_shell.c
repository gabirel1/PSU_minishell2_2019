/*
** EPITECH PROJECT, 2020
** init_shell.c
** File description:
** init_shell.c
*/

#include "../include/main.h"

void do_fork(char *path_final, char *args[], char *env[])
{
    int status = 0;
    int signal = 0;

    if (fork() == 0) {
            execve(path_final, args, env);
            print_exec_error(args, path_final);
    } else {
        wait(&status);
        signal = WTERMSIG(status);
        if (signal == SIGFPE) {
            my_printf("Floating exception");
            if (__WCOREDUMP(status))
                my_printf(" (core dumped)");
            write(1, "\n", 1);
        } else if (signal != 0) {
            my_putstr(strsignal(signal));
            if (__WCOREDUMP(status))
                my_printf(" (core dumped)");
            write(1, "\n", 1);
        }
    }
}

char *current_dir(void)
{
    char *buffer = NULL;
    size_t len = 0;
    char *tmp = NULL;
    char *curr = NULL;
    int i = 0;
    int j = 0;

    tmp = getcwd(buffer, len);
    curr = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    curr[0] = 0;

    for (; tmp[i]; i++);
    i--;
    for (; i > 0 && tmp[i] != '/'; i--) {
        curr[j++] = tmp[i];
    }
    curr[j] = 0;

    free(tmp);
    return (my_revstr(curr));
}

void my_free(char *buffer, char *string, char *tab[])
{
    free(buffer);
    free(string);
}

int init_shell(char *env[], my_shell_t *shell)
{
    char *buffer = NULL;
    char *buf = NULL;
    size_t length = 0;
    size_t len = 0;
    char **args = NULL;
    char *path_final = NULL;
    parsing(shell, env);

    while (1) {
        if (isatty(0)) {
            shell->curr.curr = current_dir();
            my_printf("[%s]$ ", shell->curr.curr);
            free(shell->curr.curr);
        }
        if (getline(&buffer, &len, stdin) == -1)
            return (0);
        if (buffer[0] == '\n')
            continue;
        buffer = clean_string(buffer);
        args = my_str_to_word_array(buffer, ' ');
        path_final = get_path(shell, args);
        if (check_buffer_and_exec_function(buffer, args, shell, env) == 2 \
        || shell->return_status == 1)
            continue;
        do_fork(path_final, args, env);
        reset_streams(shell);
        my_free(buffer, path_final, args);
        len = 0;
    }
    return (0);
}