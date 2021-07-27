/*
** EPITECH PROJECT, 2021
** maze_maze
** File description:
** .
*/

#include "../include/generator.h"
#include "../include/stack.h"

int visited(stack_t **ptr, int x, int y)
{
    stack_t *save = *ptr;

    while (save != NULL && (x != save->x && y != save->y))
        save = save->next;
    if (save != NULL)
        return (0);
    return (1);
}

void find_un_cells(stack_t **pile, stack_t **un_cells, char **maze)
{
    int x = (*pile)->x;
    int y = (*pile)->y;

    if (y - 2 >= 0 && maze[y - 2][x] != '*')
        if (visited(pile, x, y - 2) == 0)
            add_node(un_cells, x, y - 2);
    if (x - 2 >= 0 && maze[y][x - 2] != '*')
        if (visited(pile, x - 2, y) == 0)
            add_node(un_cells, x - 2, y);
    if ((size_t){x + 2} < strlen(maze[y]) && maze[y][x + 2] != '*')
        if (visited(pile, x + 2, y) == 0)
            add_node(un_cells, x + 2, y);
    if (y + 2 < arr_size(maze) && maze[y + 2][x] != '*')
        if (visited(pile, x, y + 2) == 0)
            add_node(un_cells, x, y + 2);
}

int get_random(int n, int m)
{
    int res = -1;

    while (res < 0)
        res = random() % ((n - m + 1) + m);
    return (res);
}

char **update_map(stack_t **pile, stack_t **un_cells, int cell, char **maze)
{
    int x;
    int y;

    for (int i = 0; (*un_cells)->next != NULL && i < cell; i++)
        *un_cells = (*un_cells)->next;
    x = (*pile)->x - (*un_cells)->x;
    y = (*pile)->y - (*un_cells)->y;
    if (x == 2)
        for (int i = 0; (*pile)->x - i >= 0 && i < 3; i++)
            maze[(*pile)->y][(*pile)->x - i] = '*';
    if (x == -2)
        for (int i = 0; maze[(*pile)->y][(*pile)->x + i] != '\0' && i < 3; i++)
            maze[(*pile)->y][(*pile)->x + i] = '*';
    if (y == 2)
        for (int i = 0; (*pile)->y - i >= 0 && i < 3; i++)
            maze[(*pile)->y - i][(*pile)->x] = '*';
    if (y == -2)
        for (int i = 0; maze[(*pile)->y + i] != 0 && i < 3; i++)
            maze[(*pile)->y + i][(*pile)->x] = '*';
    return (maze);
}

void make_maze_rec(stack_t **pile, char **maze)
{
    stack_t *un_cells = NULL;
    int size;
    int cell;
    stack_t *save;

    find_un_cells(pile, &un_cells, maze);
    save = un_cells;
    size = list_size(&un_cells);
    if (size > 0) {
        cell = get_random(size, 0);
        update_map(pile, &un_cells, cell, maze);
        add_node(pile, un_cells->x, un_cells->y);
    } else
        pop_node(pile);
    destroy_stack(&save);
}
