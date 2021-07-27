/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_revstr(char *str);

char **my_str_to_word_array(char *str);

char *my_strcat(char *dest, char *src);

int my_strcmp(char *str_o, char *str_c);

char *my_strdup(char* str);