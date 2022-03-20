/*
** EPITECH PROJECT, 2018
** green_mid_duck.c
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

sfIntRect Grect_MD(sfIntRect *Grectangle) {
    Grectangle->top = 170;
    Grectangle->left = 650;
    Grectangle->width = 150;
    Grectangle->height = 120;
}

void Gmove_image_MD(sfIntRect *Grectangle) {
    if (Grectangle->left < 700)
        Grectangle->left += 150;
    else
        Grectangle->left = 650;
}

void Gmove_MD(ducker *duck) {
    sfSprite_move(duck->sprite, duck->speed);
}
