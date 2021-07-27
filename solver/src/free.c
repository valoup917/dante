/*
** EPITECH PROJECT, 2021
** free
** File description:
**
*/

#include <solver.h>

map_t *free_struct(map_t *maze)
{
    for (int i = 0; maze->map[i];i++) {
        free(maze->map[i]);
    }
    free(maze->node);
    free(maze->map);
    free(maze->string);
    return maze;
}

int check_already_dead(map_t *maze)
{
    int x = maze->len_x - 1;
    int y = maze->len_y - 1;

    if (maze->map[y][x] == 'X' || maze->map[0][0] == 'X')
        return 1;
    return 0;
}

int fin_len_x(char **map)
{
    int a = 0;

    for (; map[0][a] != '\0'; a++);
    return a;
}

int fin_len_y(char **map)
{
    int a = 0;

    for (;map[a];a++);
    return a;
}

void print_map(map_t *maze)
{
    for (int i = 0; maze->map[i];i++) {
        if (maze->map[i+1])
            my_printf("%s\n", maze->map[i]);
        else
            my_printf("%s", maze->map[i]);
    }
    return;
}

void change_all(map_t *maze)
{
    for (int i = 0; maze->map[i];i++) {
        for (int y = 0; maze->map[i][y] != '\0'; y++) {
            if (maze->map[i][y] == 'g' || maze->map[i][y] == 'h')
                maze->map[i][y] = 'o';
            else if (maze->map[i][y] == 'd' || maze->map[i][y] == 'b')
                maze->map[i][y] = 'o';
        }
    }
    print_map(maze);
}