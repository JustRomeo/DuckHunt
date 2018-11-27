/*
** EPITECH PROJECT, 2018
** input.c
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

int killing(sfVector2i mouse, ducker *duck, ducker *duck2, ducker *duck3, sfSound *shot,
            int height, int width, int *hit)
{
    sfVector2f duckpos = sfSprite_getPosition(duck->sprite);
    sfVector2f duckpos2 = sfSprite_getPosition(duck2->sprite);
    sfVector2f duckpos3 = sfSprite_getPosition(duck3->sprite);

    srand (time (NULL));
    if (mouse.x >= duckpos.x && mouse.x <= duckpos.x + 110 && mouse.y <= duckpos.y + 110 &&
        mouse.y >= duckpos.y) {
        pink_duck_init(duck, height, width);
        //sfSound_play(shot); STARFOULA C'EST LE SON QUI SEGFAULT
        (*hit)--;
        return (100);
    }
    else if (mouse.x >= duckpos2.x && mouse.x <= duckpos2.x + 110 &&
             mouse.y <= duckpos2.y + 110 && mouse.y >= duckpos2.y) {
        green_duck_init(duck2, height, width);
        //sfSound_play(shot); STARFOULA C'EST LE SON QUI SEGFAULT
        (*hit)--;
        return (150);
    }
    else if (mouse.x >= duckpos3.x && mouse.x <= duckpos3.x + 110 &&
             mouse.y <= duckpos3.y + 110 && mouse.y >= duckpos3.y) {
        RL_duck_init(duck3, height, width);
        //sfSound_play(shot); STARFOULA C'EST LE SON QUI SEGFAULT
        (*hit)--;
        return (200);
    }
    else {
        (*hit)--;
        //sfSound_play(shot); STARFOULA C'EST LE SON QUI SEGFAULT
        return (0);
    }
}

int input_event(sfMouseButtonEvent event, sfRenderWindow *window, sfVector2i mouse,
                ducker *duck, ducker *duck2, ducker *duck3, sfSound *shot, int height,
                int width, int *hit)
{
    int score = 0;

    switch (event.type) {
    case sfEvtMouseButtonPressed : score = killing(mouse, duck, duck2, duck3, shot, height,
                                                   width, hit); break;
    case sfEvtClosed : sfRenderWindow_close(window); break;
    case sfEvtKeyPressed : sfRenderWindow_close(window); break;
    }
    return (score);
}

void usage() {
    write(1, "USAGE\n./my_hunter map\n\nDESCRIPTION\n", 35);
    write(1, "This game is an point and click.\n", 33);
    write(1, "The ducks appear, and the player has to shoot them down.\n", 57);
    write(1, "The player receives points upon shooting each duck.\n", 52);
    write(1, "The bullet's number is limited.\n", 35);
    exit ("");
}
