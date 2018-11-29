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

void drawing(sfRenderWindow *window, ducker *pink, ducker *green,
             ducker *dog, ducker *RL)
{
    sfRenderWindow_drawSprite(window, pink->sprite, NULL);
    sfRenderWindow_drawSprite(window, green->sprite, NULL);
    sfRenderWindow_drawSprite(window, RL->sprite, NULL);
    sfRenderWindow_drawSprite(window, dog->sprite, NULL);

    sfSprite_setTexture(pink->sprite, pink->texture, sfTrue);
    sfSprite_setTexture(green->sprite, green->texture, sfTrue);
    sfSprite_setTexture(RL->sprite, RL->texture, sfTrue);
    sfSprite_setTexture(dog->sprite, dog->texture, sfTrue);

    sfSprite_setTextureRect(pink->sprite, pink->rect);
    sfSprite_setTextureRect(green->sprite, green->rect);
    sfSprite_setTextureRect(RL->sprite, RL->rect);
    sfSprite_setTextureRect(dog->sprite, dog->rect);
}

void drawing2(sfRenderWindow *window, cursor *cursor, Back *back, sfVector2i *mouse)
{
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    sfRenderWindow_drawSprite(window, back->sprite, NULL);

    (*mouse) = sfMouse_getPositionRenderWindow(window);
    cursor->pos.x = (float)mouse->x - 50;
    cursor->pos.y = (float)mouse->y - 55;
        
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfRenderWindow_drawSprite(window, cursor->sprite, NULL);
    sfSprite_setPosition(cursor->sprite, cursor->pos);
    
}

void mover(ducker *pink, ducker *green, ducker *RL, dogger *dog)
{
    move(pink);
    move(green);
    move(RL);
    movement_dog(dog);
}

void timer(Clocker *clock, Clocker *clock2, float *seconds)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock2->time = sfClock_getElapsedTime(clock2->clock);
    (*seconds) = clock->time.microseconds / 1000000.0;
}
