/*
** EPITECH PROJECT, 2018
** proto.h
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

void init_SPRITE();

sfIntRect rect_MD(sfIntRect *rectangle);
void move_image_MD(sfIntRect *rectangle);
void move_MD(sfSprite *sprite);

sfIntRect rect_RL(sfIntRect *rectangle);
void move_image_RL(sfIntRect *rectangle);
void move_RL(sfSprite *sprite);

void move_dog(sfIntRect *dogrect);
sfIntRect rect_dog(sfIntRect *dogrect);
void movement_dog(sfSprite *sprite);

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height);
int window_properties(unsigned int width, unsigned int height);

void mouse_co(sfMouseButtonEvent event, sfRenderWindow *window);
void analyse_events(sfRenderWindow *window, sfEvent event);

void killing(sfVector2i mouse, sfSprite *duck, sfSprite *duck2, sfSprite *duck3);
void input_event(sfMouseButtonEvent event, sfRenderWindow *window, sfVector2i mouse,
                 sfSprite *duck, sfSprite *duck2, sfSprite *duck3);

