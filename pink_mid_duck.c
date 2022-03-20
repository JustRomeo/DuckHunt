/*
** EPITECH PROJECT, 2018
** pink_mid_duck.c
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

sfIntRect rect_MD(sfIntRect *rectangle) {
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = 110;
    rectangle->height = 110;
}

void move_image_MD(sfIntRect *rectangle) {
    rectangle->left = rectangle->left < 220 ? rectangle->left + 110 : 0;
}

void move(ducker *duck) {
    sfSprite_move(duck->sprite, duck->speed);
}

void move_image_mid(ducker *duck, sfIntRect *rectangle) {
    if (duck->rect.left < 250)
        rectangle->left = rectangle->left < 249 ? rectangle->left + 83 : 0;
    else if (duck->rect.left < 500)
        rectangle->left = rectangle->left < 498 ? rectangle->left + 83 : 250;
    else
        rectangle->left = rectangle->left < 697 ? rectangle->left + 83 : 750;
}
