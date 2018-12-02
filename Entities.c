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

void init_pos(unsigned int width, unsigned int height, Back *back,
              cursor *cursor)
{
    back->texture = sfTexture_createFromFile
        ("ressources/sprite_back.png", NULL);
    back->sprite = sfSprite_create();
    back->size.x = 4;
    back->size.y = 4;
    sfSprite_setScale(back->sprite, back->size);
    cursor->texture = sfTexture_createFromFile
        ("ressources/sprite_cursor.png", NULL);
    cursor->sprite = sfSprite_create();
    cursor->size.x = 0.4;
    cursor->size.y = 0.4;
    sfSprite_setScale(cursor->sprite, cursor->size);
}

void dog_init(dogger *dog, int height)
{
    srand (time (NULL));
    dog->texture = sfTexture_createFromFile
        ("ressources/sprite_dog.png", NULL);
    dog->sprite = sfSprite_create();
    dog->rect.top = 0;
    dog->rect.left = 12;
    dog->rect.width = 180;
    dog->rect.height = 168;
    dog->init.x = -1 * rand() %(100);
    dog->init.y = height - 220;
    dog->speed.x = 2 + rand() %(3);
    dog->speed.y = 0;
    sfSprite_setPosition(dog->sprite, dog->init);
}

void pink_duck_init(ducker *duck, int height, int width)
{
    srand (time (NULL));
    duck->texture = sfTexture_createFromFile
        ("ressources/sprite_duck_medium.png", NULL);
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
    duck->texture= sfTexture_createFromFile("ressources/sprite_dog.png", NULL);
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
    duck->texture= sfTexture_createFromFile("ressources/sprite_dog.png", NULL);
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
