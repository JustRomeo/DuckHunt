/*
** EPITECH PROJECT, 2018
** Looper.c
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

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height) {
    sfRenderWindow  *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My Hunter", sfDefaultStyle, NULL);
    return (window);
}

void close_window(sfRenderWindow *window, int scores, int *Game) {
    sfRenderWindow_close(window);
    my_printf("Score : %d\n", scores);
    (*Game) = 2;
}

int window_properties(unsigned int width, unsigned int height, int *Game) {
    sfRenderWindow *window = createMyWindow(width, height);
    sfMouseButtonEvent event;
    sfMusic *music = sfMusic_createFromFile("ressources/sound_shot.wav");
    Back back;
    cursor cursor;
    dogger dog;
    ducker pink;
    ducker green;
    ducker RL;
    Clocker Clock;
    Clocker Clock2;
    Stats stats;

    start_init(height, width, &pink, &green);
    start_init2(height, width, &RL, &dog);
    start_init3(&Clock, &Clock2, window, &stats);
    init_pos(width, height, &back, &cursor);
    while (sfRenderWindow_isOpen(window)) {
        timer(&Clock, &Clock2, &stats.seconds);
        sfRenderWindow_clear(window, sfWhite);
        drawing2(window, &cursor, &back, &stats.mouse);
        drawing(window, &pink, &green, &RL, &dog);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        if (stats.seconds > 0.15) {
            tempo_sprite(&pink.rect, &green.rect, &RL.rect, &dog.rect);
            sfClock_restart(Clock.clock);
        } if (Clock2.time.microseconds > 10000) {
            mover(&pink, &green, &RL, &dog);
            sfClock_restart(Clock2.clock);
            init_clean(height, width, &pink, &green, &RL, &dog);
        }
        display_bullet(window, stats.hit, width, height);
        while (sfRenderWindow_pollEvent(window, &event) && stats.hit > 0)
            stats.scores += input_event(event, window, stats.mouse, &pink, &green, &RL, music, height, width, &stats.hit);
        if (stats.hit == 0 && stats.amo > 1) {
            stats.hit = 10;
            stats.amo --;
        }
        sfRenderWindow_display(window);
        if (stats.hit == 0 && stats.amo == 1)
            break;
    }
    close_window(window, stats.scores, Game);
    return (0);
}
