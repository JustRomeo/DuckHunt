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

#include "include/my.h"
#include "include/proto.h"

void Gamemode(int *Game) {
    while ((*Game) < 3) {
        if ((*Game) == 0)
            (*Game) = Mainscreen (655, 270, Game);
        if ((*Game) == 1)
            window_properties(1920, 1080, Game);
        if ((*Game) == 2)
            (*Game) = EndScreen(1600, 950, Game);
    }
}

int main(int ac, char **argv) {
    int Game = 0;

    if (ac > 1 && ac < 3 && argv[1][0] == '-' && argv[1][1] == 'h')
        usage();
    else if (ac == 1)
        Gamemode(&Game);
    else
        write(1, "Unknow arguments :(\n", 20);
    return (0);
}
