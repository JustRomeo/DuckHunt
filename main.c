/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** header
*/

#include "include/proto.h"
#include "include/my.h"

int main (int ac, char **argv)
{
    int hit = 10;
    int amo = 2;

    if (ac > 1 && ac < 3 && argv[1][0] == '-') {
        if (argv[1][1] == 'h')
            usage();
    }
    if (ac == 1)
        window_properties(1920, 1080, hit, amo);
    else
        write(1, "Unknow arguments :(\n", 20);
    return(0);
}
