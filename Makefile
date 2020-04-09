##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

LIB = 		lib/my/clean_buffer.c 			\
			lib/my/my_getnbr.c				\
			lib/my/my_strcmp.c				\
			lib/my/my_put_nbr.c				\
			lib/my/my_putchar.c				\
			lib/my/my_putstr.c				\
			lib/my/my_revstr.c				\
			lib/my/my_strcat.c				\
			lib/my/my_strcpy.c				\
			lib/my/my_strlen.c				\
			lib/my/my_strncmp.c				\
			lib/my/str_to_word_array.c

SRC =		src/main.c					\
			src/my_cd.c					\
			src/parse_env.c				\
			src/check_buffer.c			\
			src/clean_string.c			\
			src/get_env.c				\
			src/init_shell.c			\
			src/print_exec_error.c		\
			src/my_saver.c				

MY_PRINTF = 	$(wildcard lib/my_printf/*.c)

CFLAGS = 	-Wextra -W -Wall -Wextra

DEBUG = 	-g3

CC	= 	gcc

OBJ = $(SRC:.c=.o) $(MY_PRINTF:.c=.o)

NAME = tetris

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(DEBUG) $(LIB) $(SRC) $(MY_PRINTF) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all