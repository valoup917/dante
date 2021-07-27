/*
** EPITECH PROJECT, 2020
** my_print
** File description:
** .
*/

#include <solver.h>

void my_redirection(va_list argptr, char str);

void my_printf(char *str, ...)
{
    va_list argptr;
    va_start(argptr, str);

    for (int i = 0; str[i] != '\0';i++)
        if (str[i] == '%') {
            my_redirection(argptr, str[i + 1]);
            i++;
        }
        else
            my_putchar(str[i]);
    va_end(argptr);
}

void my_redirection(va_list argptr, char str)
{
    if (str == 'd' || str == 'i')
        my_put_nbr(va_arg(argptr, int));
    if (str == 'S' || str == 's')
        my_putstr(va_arg(argptr, char *));
    if (str == 'c' || str == 'C')
        my_putchar(va_arg(argptr, int));
    if (str == 'u')
        usigned(va_arg(argptr, int));
    if (str == 'o')
        convert(va_arg(argptr, int), 8);
    if (str == 'X')
        convert(va_arg(argptr, int), 16);
    if (str == 'x')
        convert2(va_arg(argptr, int), 16);
    if (str == '%')
        my_putchar('%');
}

int usigned(int nbri)
{
    long nbr = nbri;
    if (nbr >= 0)
        my_put_nbr(nbr);
    else if (nbr < 0) {
        nbr = 4294967296 + nbr;
        my_put_long(nbr);
    }
    return 0;
}
