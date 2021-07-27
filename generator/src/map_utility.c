/*
** EPITECH PROJECT, 2021
** map_utility
** File description:
** .
*/

#include "../include/generator.h"

char **create_maze(int x, int y)
{
    char **maze = malloc(sizeof(char *) * (y + 1));

    if (maze == NULL)
        exit(84);
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(char) * (x + 1));
        if (maze[i] == NULL)
            exit(84);
        memset(maze[i], 'X', x);
        maze[i][x] = '\0';
    }
    maze[y] = 0;
    return (maze);
}

void end_display(char **maze)
{
    for (int i = 0; maze[i] != 0; i++) {
        printf("%s", maze[i]);
        if (maze[i + 1] != 0)
            printf("\n");
        free(maze[i]);
    }
    free(maze);
}

int arr_size(char **maze)
{
    int i = 0;

    for (; maze[i] != 0; i++);
    return (i);
}