/*
** EPITECH PROJECT, 2018
** 2init.c
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

void start_init(int height, int width, ducker *pink, ducker *green) {
    pink_duck_init(pink, height, width);
    green_duck_init(green, height, width);
}

void start_init2(int height, int width, ducker *RL, dogger *dog) {
    dog_init(dog, height);
    RL_duck_init(RL, height, width);
}

void start_init3(Clocker *Clock, Clocker *Clock2, sfRenderWindow *window, Stats *stats) {
    Clock->clock = sfClock_create();
    Clock2->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(window, 60);
    stats->seconds = 0;
    stats->scores = 0;
    stats->hit = 10;
    stats->amo = 2;
}
