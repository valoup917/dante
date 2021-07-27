/*
** EPITECH PROJECT, 2021
** perfect_maze
** File description:
** .
*/

#include "../include/generator.h"
#include "../include/stack.h"

void perfect_maze(int x, int y)
{
    char **maze = create_maze(x, y);
    stack_t *pile = NULL;

    srandom(time(NULL));
    add_node(&pile, 0, 0);
    while (list_size(&pile) > 0)
        make_maze_rec(&pile, maze);
    if (x % 2 == 0 || y % 2 == 0) {
        maze[y - 2][x - 1] = '*';
        maze[y - 1][x - 1] = '*';
    }
    end_display(maze);
    destroy_stack(&pile);
}
