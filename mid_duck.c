/*
** EPITECH PROJECT, 2018
** mid_duck.c
** File description:
** HEADER
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System.h>

#include "include/proto.h"
#include "include/my.h"
#include "include/framebuffer.h"

sfIntRect rect_MD(sfIntRect *rectangle)
{
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = 110;
    rectangle->height = 110;
}

void move_image_MD(sfIntRect *rectangle)
{
    if (rectangle->left < 220)
        rectangle->left += 110;
    else
        rectangle->left = 0;
}

void move_MD(sfSprite *sprite)
{
    sfVector2f vector;

    vector.x = 2;
    vector.y = 0;
    sfSprite_move(sprite, vector);
}
