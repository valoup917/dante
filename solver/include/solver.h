/*
** EPITECH PROJECT, 2021
** solver include
** File description:
** .
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <string.h>
#include <time.h>
#include <stdio.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct map_s
{
    char *string;
    char **map;
    int len_x;
    int len_y;
    int *node;
} map_t;

map_t *free_struct(map_t *maze);
int check_already_dead(map_t *maze);
int fin_len_x(char **map);
int fin_len_y(char **map);
void print_map(map_t *maze);

void my_printf(char *str, ...);
void convert(long number_to_convert, int base);
void convert2(long number_to_convert, int base);
int usigned(int nbri);
long my_put_long(long nb);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putchar(char c);
int my_getnbr(char *str);
void change_all(map_t *maze);

//my_str_to_word_array.c
char **my_str_to_word_array(char *str);

//algorithme.c:
void my_algo(char *path);

//read_open_file.c :
char *open_read_file(char const *filepath);

#endif