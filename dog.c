/*
** EPITECH PROJECT, 2018
** dog.c
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

void move_dog(sfIntRect *dogrect)
{
    if (dogrect->left < 550)//700)
        dogrect->left += 180;
    else
        dogrect->left = 12;
}

sfIntRect rect_dog(sfIntRect *dogrect)
{
    dogrect->top = 0;
    dogrect->left = 10;
    dogrect->width = 180;
    dogrect->height = 168;
}

void movement_dog(sfSprite *sprite)
{
    sfVector2f vector;

    vector.x = 1;
    vector.y = 0;
    sfSprite_move(sprite, vector);
}
