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
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/Time.h>
#include <SFML/System/InputStream.h>

#include "include/my.h"
#include "include/proto.h"

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
        //sfSound_play(shot);
        *hit --;
        return (100);
    }

    else if (mouse.x >= duckpos2.x && mouse.x <= duckpos2.x + 110 &&
             mouse.y <= duckpos2.y + 110 && mouse.y >= duckpos2.y) {
        green_duck_init(duck2, height, width);
        //sfSound_play(shot);
        *hit --;
        return (150);
    }

    else if (mouse.x >= duckpos3.x && mouse.x <= duckpos3.x + 110 &&
             mouse.y <= duckpos3.y + 110 && mouse.y >= duckpos3.y) {
        RL_duck_init(duck3, height, width);
        //sfSound_play(shot);
        *hit --;
        return (200);
    }

    else {
        *hit --;
        //sfSound_play(shot);
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
