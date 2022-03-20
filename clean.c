/*
** EPITECH PROJECT, 2018
** clean.c
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

void init_clean(int height, int width, ducker *duck, ducker *duck2, ducker *duck3, dogger *dog) {
    sfVector2f duckpos = sfSprite_getPosition(duck->sprite);
    sfVector2f duckpos2 = sfSprite_getPosition(duck2->sprite);
    sfVector2f duckpos3 = sfSprite_getPosition(duck3->sprite);
    sfVector2f dogpos = sfSprite_getPosition(dog->sprite);

    if (duckpos.x > width)
        pink_duck_init(duck, height, width);
    if (duckpos2.x > width)
        green_duck_init(duck2, height, width);
    if (duckpos3.x < -110 || duckpos3.y < -110)
        RL_duck_init(duck3, height, width);
    if (dogpos.x > width)
        dog_init(&dog, height);
}
