/*
** EPITECH PROJECT, 2018
** opening_windows.c
** File description:
** header
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

void close_window(sfRenderWindow *window)
{

}

int window_properties(unsigned int width, unsigned int height)
{
    sfRenderWindow *window = createMyWindow(width, height);
    sfVideoMode *video_mode;
    sfTexture *duck_med = sfTexture_createFromFile("sprite_duck_medium.png", NULL);
    sfTexture *duck_RL = sfTexture_createFromFile("sprite_dog.png", NULL);
    sfTexture *background = sfTexture_createFromFile("sprite_back.png", NULL);
    sfTexture *cursor = sfTexture_createFromFile("sprite_cursor.jpg", NULL);
    sfTexture *dog = sfTexture_createFromFile("sprite_dog.png", NULL);
    sfSprite *s_duck_med = sfSprite_create();
    sfSprite *s_duck_RL = sfSprite_create();
    sfSprite *s_dog = sfSprite_create();
    sfSprite *s_back = sfSprite_create();
    sfSprite *s_cursor = sfSprite_create();
    sfMouseButtonEvent event;
    sfVector2i mouse;
    sfIntRect rectangle;
    sfIntRect rectangle_RL;
    sfIntRect rectangle_LR;
    sfIntRect dogrect;
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfTime time;
    sfTime moving;
    float seconds = 0;
    sfVector2f init_dog;
    sfVector2f init_duck_RL;
    sfVector2f size_back;
    sfVector2f cursor_var;
    sfVector2f cursor_size;

    init_dog.x = 10;
    init_dog.y = height - 220;
    size_back.x = 4;
    size_back.y = 4;
    cursor_size.x = 0.4;
    cursor_size.y = 0.4;
    init_duck_RL.x = width - 100;
    init_duck_RL.y = height - 100;

    rect_MD(&rectangle);
    rect_RL(&rectangle_RL);
    rect_dog(&dogrect);
    sfSprite_setPosition(s_dog, init_dog);
    sfSprite_setPosition(s_duck_RL, init_duck_RL);
    sfSprite_setScale(s_back, size_back);
    sfSprite_setScale(s_cursor, cursor_size);
    
    while (sfRenderWindow_isOpen(window)) {
        mouse = sfMouse_getPositionRenderWindow(window);
        cursor_var.x = (float)mouse.x - 50;
        cursor_var.y = (float)mouse.y - 55;
    
        time = sfClock_getElapsedTime(clock);
        moving = sfClock_getElapsedTime(clock2);
        seconds = time.microseconds / 1000000.0;

        sfRenderWindow_clear(window, sfWhite);
        
        sfSprite_setTexture(s_back, background, sfTrue);
        sfSprite_setTexture(s_duck_med, duck_med, sfTrue);
        sfSprite_setTexture(s_duck_RL, duck_RL, sfTrue);
        sfSprite_setTexture(s_dog, dog, sfTrue);
        sfSprite_setTexture(s_cursor, cursor, sfTrue);
        
        sfRenderWindow_drawSprite(window, s_back, NULL);

        sfSprite_setTextureRect(s_duck_med, rectangle);
        sfSprite_setTextureRect(s_duck_RL, rectangle_RL);
        sfSprite_setTextureRect(s_dog, dogrect);
        
        sfRenderWindow_drawSprite(window, s_duck_med, NULL);
        sfRenderWindow_drawSprite(window, s_duck_RL, NULL);
        sfRenderWindow_drawSprite(window, s_dog, NULL);
        sfRenderWindow_drawSprite(window, s_cursor, NULL);
                 
        sfSprite_setPosition(s_cursor, cursor_var);
                
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);

        if (seconds > 0.15) {
            move_image_MD(&rectangle);
            move_image_RL(&rectangle_RL);
            move_dog(&dogrect);
            sfClock_restart(clock);
        }

        if (moving.microseconds > 10000) {
            move_MD(s_duck_med);
            move_RL(s_duck_RL);
            movement_dog(s_dog);
            sfClock_restart(clock2);
        }

        while (sfRenderWindow_pollEvent(window, &event))
            input_event(event, window, mouse, s_duck_med, s_duck_RL, s_duck_RL);
        
        sfRenderWindow_display(window);
    }
    sfRenderWindow_close(window);
    return (0);
}
