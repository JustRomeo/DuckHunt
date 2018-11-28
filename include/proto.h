/*
** EPITECH PROJECT, 2018
** proto.h
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

typedef struct chien
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;

    sfVector2f init;
    sfVector2f speed;
} dogger;

typedef struct canard
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;

    sfVector2f init;
    sfVector2f speed;
} ducker;

int tempo_sprite(sfIntRect *rectangle, sfIntRect *Grectangle, sfIntRect *rectangle_RL,
                 sfIntRect *dogrect, float *seconds);

sfIntRect rect_MD(sfIntRect *rectangle);
void move_image_MD(sfIntRect *rectangle);
void move(ducker *duck);

sfIntRect Grect_MD(sfIntRect *Grectangle);
void Gmove_image_MD(sfIntRect *Grectangle);

sfIntRect rect_RL(sfIntRect *rectangle);
void move_image_RL(sfIntRect *rectangle);

void move_dog(sfIntRect *dogrect);
sfIntRect rect_dog(sfIntRect *dogrect);
void movement_dog(dogger *dog);

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height);
void close_window(sfRenderWindow *window, sfSound *shot, sfSoundBuffer *soundbuffer_shot);
int window_properties(unsigned int width, unsigned int height);

void mouse_co(sfMouseButtonEvent event, sfRenderWindow *window);
void analyse_events(sfRenderWindow *window, sfEvent event);

void display_bullet(sfRenderWindow *window, int bullet, int width, int height);

void green_duck_init(ducker *duck, int height, int width);
void RL_duck_init(ducker *duck, int height, int width);
void pink_duck_init(ducker *duck, int height, int width);
void dog_init(dogger *dog, int height);
void move_image_mid(ducker *duck, sfIntRect *rectangle);

void init_clean(int height, int width, ducker *duck, ducker *duck2, ducker *duck3,
                dogger *dog);

void init_pos(unsigned int width, unsigned int height, dogger dog,
              sfVector2f *size_back, sfVector2f *cursor_var, sfVector2f *cursor_size);

int input_event(sfMouseButtonEvent event, sfRenderWindow *window, sfVector2i mouse,
                ducker *duck, ducker *duck2, ducker *duck3, sfSound *shot, int height,
                int width, int *hit);
