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

void close_window(sfRenderWindow *window, sfSound *shot, sfSoundBuffer *soundbuffer_shot)
{
    sfSound_destroy(shot);
    sfSoundBuffer_destroy(soundbuffer_shot);
    sfRenderWindow_close(window);
}

int window_properties(unsigned int width, unsigned int height)
{
    sfRenderWindow *window = createMyWindow(width, height);
    sfVideoMode *video_mode;
    sfTexture *background = sfTexture_createFromFile("sprite_back.png", NULL);
    sfTexture *cursor = sfTexture_createFromFile("sprite_cursor.png", NULL);
    sfSprite *s_back = sfSprite_create();
    sfSprite *s_cursor = sfSprite_create();
    sfMouseButtonEvent event;
    sfVector2i mouse;
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfTime time;
    sfTime moving;
    float seconds = 0;
    sfVector2f size_back;
    sfVector2f cursor_var;
    sfVector2f cursor_size;
    int scores = 0;
    int hit = 10;
    int amo = 2;
    sfSoundBuffer *soundbuffer_shot = sfSoundBuffer_createFromFile("sound_shot.wav");
    sfSound *shot = sfSound_create();
    dogger dog;
    ducker pink_duck;
    ducker green_duck;
    ducker RL_duck;

    dog_init(&dog, height);
    pink_duck_init(&pink_duck, height, width);
    green_duck_init(&green_duck, height, width);
    RL_duck_init(&RL_duck, height, width);
    sfSound_setBuffer(shot, soundbuffer_shot);
    init_pos(width, height, dog, &size_back, &cursor_var, &cursor_size);
    sfSprite_setScale(s_back, size_back);
    sfSprite_setScale(s_cursor, cursor_size);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        mouse = sfMouse_getPositionRenderWindow(window);
        cursor_var.x = (float)mouse.x - 50;
        cursor_var.y = (float)mouse.y - 55;
        time = sfClock_getElapsedTime(clock);
        moving = sfClock_getElapsedTime(clock2);
        seconds = time.microseconds / 1000000.0;
        sfRenderWindow_clear(window, sfWhite);
        sfSprite_setTexture(s_back, background, sfTrue);
        sfSprite_setTexture(pink_duck.sprite, pink_duck.texture, sfTrue);
        sfSprite_setTexture(green_duck.sprite, green_duck.texture, sfTrue);
        sfSprite_setTexture(RL_duck.sprite, RL_duck.texture, sfTrue);
        sfSprite_setTexture(dog.sprite, dog.texture, sfTrue);
        sfSprite_setTexture(s_cursor, cursor, sfTrue);
        sfRenderWindow_drawSprite(window, s_back, NULL);
        sfSprite_setTextureRect(pink_duck.sprite, pink_duck.rect);
        sfSprite_setTextureRect(green_duck.sprite, green_duck.rect);
        sfSprite_setTextureRect(RL_duck.sprite, RL_duck.rect);
        sfSprite_setTextureRect(dog.sprite, dog.rect);
        sfRenderWindow_drawSprite(window, pink_duck.sprite, NULL);
        sfRenderWindow_drawSprite(window, green_duck.sprite, NULL);
        sfRenderWindow_drawSprite(window, RL_duck.sprite, NULL);
        sfRenderWindow_drawSprite(window, dog.sprite, NULL);
        sfRenderWindow_drawSprite(window, s_cursor, NULL);
        sfSprite_setPosition(s_cursor, cursor_var);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        if (seconds > 0.15) {
            tempo_sprite(&pink_duck.rect, &green_duck.rect, &RL_duck.rect, &dog.rect,
                         &seconds);
            sfClock_restart(clock);
        }
        if (moving.microseconds > 10000) {
            move(&pink_duck);
            move(&green_duck);
            move(&RL_duck);
            movement_dog(&dog);
            sfClock_restart(clock2);
            init_clean(height, width, &pink_duck, &green_duck, &RL_duck, &dog);
        }
        display_bullet(window, hit, width, height);
        while (sfRenderWindow_pollEvent(window, &event) && hit > 0) {
            scores += input_event(event, window, mouse, &pink_duck, &green_duck, &RL_duck,
                                  shot, height, width, &hit);
        }
        if (hit == 0 && amo > 1) {
            hit = 10;
            amo --;
        }
        sfRenderWindow_display(window);
        if (hit == 0 && amo == 1)
            break;
    }
    close_window(window, shot, soundbuffer_shot);
    my_printf("Score : %d\n", scores);
    return (0);
}
