/*
** EPITECH PROJECT, 2021
** generator
** File description:
** .
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char **create_maze(int x, int y);
void perfect_maze(int x, int y);
int get_random(int n, int m);
int imperfect_maze(int x, int y);
void end_display(char **maze);
int arr_size(char **maze);

#endif