/*
** EPITECH PROJECT, 2018
** init.c
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

void init_pos(unsigned int width, unsigned int height, dogger dog, sfVector2f *size_back,
              sfVector2f *cursor_var, sfVector2f *cursor_size)
{
    size_back->x = 4;
    size_back->y = 4;
    cursor_size->x = 0.4;
    cursor_size->y = 0.4;
}

void dog_init(dogger *dog, int height)
{
    dog->texture = sfTexture_createFromFile("sprite_dog.png", NULL);
    dog->sprite = sfSprite_create();
    dog->rect.top = 0;
    dog->rect.left = 12;
    dog->rect.width = 180;
    dog->rect.height = 168;
    dog->init.x = 10;
    dog->init.y = height - 220;

    sfSprite_setPosition(dog->sprite, dog->init);
}

void pink_duck_init(ducker *duck, int height, int width)
{
    srand (time (NULL));
    duck->texture = sfTexture_createFromFile("sprite_duck_medium.png", NULL);
    duck->sprite = sfSprite_create();
    duck->rect.top = 0;
    duck->rect.left = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    duck->init.x = -150;
    duck->init.y = rand() %(height - 300);
    duck->speed.x = 5 + rand() %(5);
    duck->speed.y = 0;

    sfSprite_setPosition(duck->sprite, duck->init);
}

void green_duck_init(ducker *duck, int height, int width)
{
    srand (time (NULL));
    duck->texture= sfTexture_createFromFile("sprite_dog.png", NULL);
    duck->sprite = sfSprite_create();
    duck->rect.top = 170;
    duck->rect.left = 650;
    duck->rect.width = 150;
    duck->rect.height = 120;
    duck->init.x = -10;
    duck->init.y = rand() %(height - 300);
    duck->speed.x = 5 + rand() %(5);
    duck->speed.y = 0;

    sfSprite_setPosition(duck->sprite, duck->init);
}

void RL_duck_init(ducker *duck, int height, int width)
{
    srand (time (NULL));
    duck->texture= sfTexture_createFromFile("sprite_dog.png", NULL);
    duck->sprite = sfSprite_create();
    duck->rect.top = 170;
    duck->rect.left = 100;
    duck->rect.width = 100;
    duck->rect.height = 120;
    duck->init.x = (width / 2) + rand() % (width / 2);
    duck->init.y = height;
    duck->speed.x = -6 + rand() %(4);
    duck->speed.y = -6 + rand() %(4);
    sfSprite_setPosition(duck->sprite, duck->init);
}
