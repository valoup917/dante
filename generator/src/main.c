/*
** EPITECH PROJECT, 2021
** main
** File description:
** .
*/

#include "../include/generator.h"

void print_help(void)
{
    write(2, "USAGE:  ./generator x y [perfect]\n", 34);
    exit(84);
}

int main(int ac, char **av)
{
    int x;
    int y;

    if (ac < 3 || ac > 4)
        print_help();
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 1 || y < 1)
        return (0);
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        perfect_maze(x, y);
    else
        imperfect_maze(x, y);
    return (0);
}
