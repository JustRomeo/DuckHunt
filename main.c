/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** header
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "include/proto.h"
#include "include/my.h"

int main(int ac, char **argv)
{
    int hit = 10;
    int amo = 2;
    int Game = 0;

    if (ac > 1 && ac < 3 && argv[1][0] == '-' && argv[1][1] == 'h')
        usage();
    else if (ac == 1) {
        while (Game != 2) {
            if (Game == 0)
                Game = Mainscreen (680, 300, &Game);
            if (Game == 1)
                window_properties(1920, 1080, hit, amo, &Game);
            else
                break;
        }
    }
    else
        write(1, "Unknow arguments :(\n", 20);
    return(0);
}
