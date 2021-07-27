/*
** EPITECH PROJECT, 2021
** imperfect_maze
** File description:
** .
*/

#include "../include/generator.h"

char *randomize_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (get_random(1, 0) == 1)
            line[i] = '*';
    return (line);
}

int imperfect_maze(int x, int y)
{
    char **maze = create_maze(x, y);

    srandom(time(NULL));
    for (int i = 0; maze[i] != 0; i++)
        maze[i] = randomize_line(maze[i]);
    end_display(maze);
    exit(0);
}
