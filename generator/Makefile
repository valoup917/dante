##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	src/main.c	\
		src/perfect_maze.c	\
		src/node_utility.c	\
		src/make_maze.c	\
		src/imperfect_maze.c	\
		src/map_utility.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(FLAGS) $(SRC) -g3

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f src/*~
	rm -f include/*~

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
