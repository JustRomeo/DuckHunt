/*
** EPITECH PROJECT, 2018
** RL_duck.c
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

sfIntRect rect_RL(sfIntRect *rectangle_RL)
{
    rectangle_RL->top = 170;
    rectangle_RL->left = 100;
    rectangle_RL->width = 100;
    rectangle_RL->height = 120;
}

void move_image_RL(sfIntRect *rectangle_RL)
{
    if (rectangle_RL->left < 400)
        rectangle_RL->left += 330;
    else
        rectangle_RL->left = 100;
}
void move_RL(ducker *duck)
{
    sfSprite_move(duck->sprite, duck->speed);
}
