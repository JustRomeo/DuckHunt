/*
** EPITECH PROJECT, 2018
** tempo_sprite.c
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

int tempo_sprite(sfIntRect *rectangle, sfIntRect *Grectangle,
                 sfIntRect *rectangle_RL, sfIntRect *dogrect, float *seconds)
{
    move_image_MD(rectangle);
    Gmove_image_MD(Grectangle);
    move_image_RL(rectangle_RL);
    move_dog(dogrect);
}

