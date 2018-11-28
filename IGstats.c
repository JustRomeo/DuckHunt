/*
** EPITECH PROJECT, 2018
** IGstats.c
** File description:
** HEADER
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

void drawing(sfRenderWindow *window, sfSprite *pink, sfSprite *green,
             sfSprite *dog, sfSprite *RL)
{
    sfRenderWindow_drawSprite(window, pink, NULL);
    sfRenderWindow_drawSprite(window, green, NULL);
    sfRenderWindow_drawSprite(window, RL, NULL);
    sfRenderWindow_drawSprite(window, dog, NULL);
}

void mover(ducker *pink, ducker *green, ducker *RL, dogger *dog)
{
    move(pink);
    move(green);
    move(RL);
    movement_dog(dog);
}
