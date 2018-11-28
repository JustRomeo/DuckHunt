/*
** EPITECH PROJECT, 2018
** my_putint_in_str.c
** File description:
** HEADER
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);

char *my_putint_in_str(int z)
{
    char *result = malloc(sizeof(char) * 12);
    if (z > 0)
        result[0] = (z % 10 + '0');
    if (z > 10)
        result[1] = (z / 10 + '0');
    if (z > 100)
        result[2] = (z / 100 + '0');
    if (z > 1000)
        result[3] = (z / 1000 + '0');
    if (z > 10000)
        result[4] = (z / 10000 + '0');
    if (z > 100000)
        result[5] = (z / 100000 + '0');
    if (z > 1000000)
        result[6] = (z / 1000000 + '0');
    if (z > 10000000)
        result[7] = (z / 10000000 + '0');
    if (z > 100000000)
        result[8] = (z / 100000000 + '0');
    if (z > 1000000000)
        result[9] = (z / 1000000000 + '0');
    return (my_revstr(result));
}
