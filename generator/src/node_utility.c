/*
** EPITECH PROJECT, 2021
** node_utility
** File description:
** .
*/

#include "../include/stack.h"
#include "../include/generator.h"

void destroy_stack(stack_t **ptr)
{
    stack_t *current = *ptr;
    stack_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *ptr = NULL;
}

int list_size(stack_t **ptr)
{
    stack_t *save = *ptr;
    int i = 0;

    for (; save != NULL; i++)
        save = save->next;
    return (i);
}

void pop_node(stack_t **ptr)
{
    stack_t *nxt = (*ptr);

    *ptr = (*ptr)->next;
    free(nxt);
}

void add_node(stack_t **pile, int x, int y)
{
    stack_t *top = malloc(sizeof(stack_t));

    if (top == NULL)
        exit(84);
    top->x = x;
    top->y = y;
    top->next = *pile;
    *pile = top;
}
