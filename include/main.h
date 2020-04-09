/*
** EPITECH PROJECT, 2020
** main.h
** File description:
** main.h
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <grp.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct saves_s
{
    int my_stdin;
    int my_stdout;
    int my_stderr;
} saves_t;

typedef struct current_dir_s
{
    char *curr;
} current_dir_t;

typedef struct my_shell_s
{
    char *env_paths;
    char *old_cd;
    char **paths;
    char *my_path;
    char **args;
    char **my_env;
    char *home_path;
    char **new_env;
    int return_status;
    saves_t save;
    current_dir_t curr;
} my_shell_t;

///////////////////////////
//          LIB          //
///////////////////////////

int my_strlen(char const *str);
char *my_revstr(char *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(char *str, char separator);
void my_printf(char *str, ...);
char *my_strcat(char *dest, char *str);
char *clean_buffer(char *str);
char *my_strcpy(char *str);

///////////////////////////
//      MINISHELL2       //
///////////////////////////

int builtin_cd(char *args[], my_shell_t *shell, char *env[]);
void print_exec_error(char *args[], char *path_final);
char **return_tab(char *tab[]);
char *cpy_line(char *str);
int get_env_size(char *env[]);
void parsing(my_shell_t *shell, char *env[]);
char *get_path(my_shell_t *shell, char **args);
void parse_env(char *env[], my_shell_t *shell);
int init_shell(char *env[], my_shell_t *shell);
void do_fork(char *path_final, char *args[], char *env[]);
char *clean_string(char *str);
int check_buffer_and_exec_function(char *buffer, char *args[], \
my_shell_t *shell, char *env[]);
void print_exec_error(char *args[], char *path_final);
void get_good_path(my_shell_t *shell, char *env[]);
void save_streams(my_shell_t *shell);
void reset_streams(my_shell_t *shell);

#endif /* !MAIN_H_ */
