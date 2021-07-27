/*
** EPITECH PROJECT, 2021
** stack
** File description:
** .
*/

#ifndef STACK_H
#define STACK_H

typedef struct stack_s {
    int x;
    int y;
    struct stack_s *next;
} stack_t;

void add_node(stack_t **pile, int x, int y);
void pop_node(stack_t **ptr);
int list_size(stack_t **ptr);
void make_maze_rec(stack_t **pile, char **maze);
void destroy_stack(stack_t **ptr);

#endif