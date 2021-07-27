##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

CC = gcc

SRC =	src/algorithme.c				\
		src/read_open_file.c 			\
		src/my_str_to_word_array.c 		\
		src/free.c 					\
		lib/my_getnbr.c		\
		lib/my_putchar.c 	\
		lib/my_putstr.c 	\
		lib/my_print.c 		\
		lib/my_put_long.c 	\
		lib/convert.c 	\
		lib/my_put_nbr.c 	\


SRC_MAIN = src/main.c

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

CFLAGS = -Wall -Wextra -pedantic

CPPFLAGS = -I./include

NAME = solver

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN)

debug: CFLAGS += -g3
debug: re

clean:
	rm -f $(OBJ) $(OBJ_MAIN)

fclean:	clean
	rm -f *gmon*
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f src/*~
	rm -f src/\*#
	rm -f include/*~
	rm -f include/*#

re: fclean all

.PHONY: all clean fclean re
