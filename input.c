/*
** EPITECH PROJECT, 2018
** input.c
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

#include "include/proto.h"
#include "include/my.h"
#include "include/framebuffer.h"

void killing(sfVector2i mouse, sfSprite *s_duck, sfSprite *s_duck2, sfSprite *s_duck3)
{
    sfVector2f duck = sfSprite_getPosition(s_duck);
    sfVector2f duck2 = sfSprite_getPosition(s_duck2);
    sfVector2f duck3 = sfSprite_getPosition(s_duck3);

    if (mouse.x >= duck.x && mouse.x <= duck.x + 110 && mouse.y <= duck.y + 110 &&
        mouse.y >= duck.y || mouse.x >= duck2.x && mouse.x <= duck2.x + 110 &&
        mouse.y <= duck2.y + 110 && mouse.y >= duck2.y || mouse.x >= duck3.x &&
        mouse.x <= duck3.x + 110 && mouse.y <= duck3.y + 110 && mouse.y >= duck3.y)
        printf("\nInjured ...");
    else
        printf("\nMissed...");
    printf(" in : x = %d\n      y = %d\n", mouse.x, mouse.y);
    
}

void input_event(sfMouseButtonEvent event, sfRenderWindow *window, sfVector2i mouse,
                 sfSprite *duck, sfSprite *duck2, sfSprite *duck3)
{
    switch (event.type) {
    case sfEvtMouseButtonPressed : killing(mouse, duck, duck2, duck3); break;
    case sfEvtClosed : sfRenderWindow_close(window); break;
    case sfEvtKeyPressed : sfRenderWindow_close(window); break;
    }        
}
