/*
** EPITECH PROJECT, 2018
** opening_windows.c
** File description:
** header
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

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow  *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My Hunter", sfDefaultStyle, NULL);
    return (window);
}

void close_window(sfRenderWindow *window, int scores, int *Game)
{
    sfRenderWindow_close(window);
    my_printf("Score : %d\n", scores);
    (*Game) = 2;
}

int window_properties(unsigned int width, unsigned int height, int hit, int amo, int *Game)
{
    sfRenderWindow *window = createMyWindow(width, height);
    sfMouseButtonEvent event;
    sfVector2i mouse;
    float seconds = 0;
    int scores = 0;
    sfMusic *music = sfMusic_createFromFile("ressources/sound_shot.wav");
    Back back;
    cursor cursor;
    dogger dog;
    ducker pink_duck;
    ducker green_duck;
    ducker RL_duck;
    Clocker Clock;
    Clocker Clock2;

    start_init(height, width, &pink_duck, &green_duck);
    start_init2(height, width, &RL_duck, &dog);
    start_init3(&Clock, &Clock2);
    init_pos(width, height, &back, &cursor);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        mouse = sfMouse_getPositionRenderWindow(window);
        cursor.pos.x = (float)mouse.x - 50;
        cursor.pos.y = (float)mouse.y - 55;
        timer(&Clock, &Clock2);
        seconds = Clock.time.microseconds / 1000000.0;
        sfRenderWindow_clear(window, sfWhite);
        drawing2(window, &cursor, &back);
        drawing(window, &pink_duck, &green_duck, &RL_duck, &dog);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        if (seconds > 0.15) {
            tempo_sprite(&pink_duck.rect, &green_duck.rect, &RL_duck.rect, &dog.rect,
                         &seconds);
            sfClock_restart(Clock.clock);
        }
        if (Clock2.time.microseconds > 10000) {
            mover(&pink_duck, &green_duck, &RL_duck, &dog);
            sfClock_restart(Clock2.clock);
            init_clean(height, width, &pink_duck, &green_duck, &RL_duck, &dog);
        }
        display_bullet(window, hit, width, height);
        while (sfRenderWindow_pollEvent(window, &event) && hit > 0) {
            scores += input_event(event, window, mouse, &pink_duck, &green_duck, &RL_duck,
                                  music, height, width, &hit);
        }
        if (hit == 0 && amo > 1) {
            hit = 10;
            amo --;
        }
        sfRenderWindow_display(window);
        if (hit == 0 && amo == 1)
            break;
    }
    close_window(window, scores, Game);
    return (0);
}
