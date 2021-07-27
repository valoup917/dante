/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** .
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int a;

    a = 1;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / a) >= 10)
        a *= 10;
    while (a > 0) {
        my_putchar((nb / a) % 10 + '0');
        a /= 10;
    }
    return 0;
}
