##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

all:
	make -C generator/

clean:
	make clean -C generator/

fclean:
	make fclean -C generator/

re: fclean all

.PHONY: all clean fclean re
