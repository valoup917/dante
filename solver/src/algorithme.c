/*
** EPITECH PROJECT, 2021
** algorithme
** File description:
**
*/

#include <solver.h>

int check_win(map_t *maze)
{
    int x = maze->len_x - 1;
    int y = maze->len_y - 1;

    if (maze->map[y][x] == 'h')
        return 1;
    return 0;
}

void do_all(map_t *maze)
{
    print_map(maze);
    int x = maze->node[0];
    int y = maze->node[1];
    if (check_win(maze) == 1) {
        change_all(maze);
        exit(0);
    }
    if (y != maze->len_y - 1 && (maze->map[y+1][x] != 'X'
    && maze->map[y+1][x] != 'h' && maze->map[y+1][x] != 'b'
    && maze->map[y+1][x] != 'g' && maze->map[y+1][x] != 'd'
    && maze->map[y+1][x])) {
        maze->map[y+1][x] = 'h';
        maze->node[1] += 1;
        do_all(maze);
    }
    else if (x != maze->len_x - 1 && (maze->map[y][x+1] != 'X'
    && maze->map[y][x+1] != 'h' && maze->map[y][x+1] != 'g'
    && maze->map[y][x+1] != 'b' && maze->map[y][x+1] != 'd'
    && maze->map[y][x+1])) {
        maze->map[y][x+1] = 'g';
        maze->node[0] += 1;
        do_all(maze);
    }
    else if (y != 0 && (maze->map[y-1][x] != 'X'
    && maze->map[y-1][x] != 'h' && maze->map[y-1][x] != 'g'
    && maze->map[y-1][x] != 'b' && maze->map[y-1][x] != 'd'
    && maze->map[y-1][x])) {
        maze->map[y-1][x] = 'b';
        maze->node[1] -= 1;
        do_all(maze);
    }
    else if (x != 0 && (maze->map[y][x-1] != 'X'
    && maze->map[y][x-1] != 'h' && maze->map[y][x-1] != 'g'
    && maze->map[y][x-1] != 'b' && maze->map[y][x-1] != 'd'
    && maze->map[y][x-1])) {
        maze->map[y][x-1] = 'd';
        maze->node[0] -= 1;
        do_all(maze);
    }
        else {
            if (maze->map[y][x] == 'h')
                maze->node[1] -= 1, do_all(maze);
            else if (maze->map[y][x] == 'g')
                maze->node[0] -= 1, do_all(maze);
            else if (maze->map[y][x] == 'b')
                maze->node[1] += 1, do_all(maze);
            else if (maze->map[y][x] == 'd')
                maze->node[0] += 1, do_all(maze);
    }
    return;
}

void my_algo(char *path)
{
    map_t *maze = malloc(sizeof(map_t));
    maze->string = open_read_file(path);
    maze->map = my_str_to_word_array(maze->string);
    maze->len_x = fin_len_x(maze->map);
    maze->len_y = fin_len_y(maze->map);
    maze->node = malloc(sizeof(int)*2);
    maze->node[0] = 0;
    maze->node[1] = 0;
    if (check_already_dead(maze) == 1) {
        write(1, "no solution found\n", 18);
        maze = free_struct(maze);
        free(maze);
        exit(0);
    }
    maze->map[0][0] = 'o';
    do_all(maze);
    maze = free_struct(maze);
    free(maze);
}