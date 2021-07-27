/*
** EPITECH PROJECT, 2020
** convert base
** File description:
** .
*/

#include <solver.h>

void convert(long number_to_convert, int base)
{
    int converted_number[64];
    int index = 0;
    char base_digits[16] = {'0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (number_to_convert != 0) {
        converted_number[index] = number_to_convert % base;
        number_to_convert = number_to_convert / base;
        ++index;
    }
    --index;
    for (;index >= 0;index--) {
        my_putchar(base_digits[converted_number[index]]);
    }
}

void convert2(long number_to_convert, int base)
{
    int converted_number[64];
    int index = 0;
    char base_digits[16] = {'0', '1', '2', '3', '4', '5',
        '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    while (number_to_convert != 0) {
        converted_number[index] = number_to_convert % base;
        number_to_convert = number_to_convert / base;
        ++index;
    }
    --index;
    for (;index >= 0;index--) {
        my_putchar(base_digits[converted_number[index]]);
    }
}