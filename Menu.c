/*
** EPITECH PROJECT, 2018
** Screen.c
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

int EVENT(sfRenderWindow *window, sfMouseButtonEvent event) {
    if (event.type == sfEvtMouseButtonPressed) {
        sfRenderWindow_close(window);
        return (1);
    } else if (event.type == sfEvtClosed){
        sfRenderWindow_close(window);
        return (3);
    }
    return (0);
}

int Mainscreen(int width, int height, int *Game) {
    sfRenderWindow *window = createMyWindow(width, height);
    sfTexture *texture = sfTexture_createFromFile("ressources/mainscreen.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMouseButtonEvent event;
    sfVector2f size;

    size.x = 2;
    size.y = 2;
    sfSprite_setScale(sprite, size);
    sfRenderWindow_setFramerateLimit(window, 40);
    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        while (sfRenderWindow_pollEvent(window, &event) && EVENT(window, event) != 0)
            return (EVENT(window, event));
        sfRenderWindow_display(window);
    }
}

int EndScreen(int width, int height, int *Game) {
    sfRenderWindow *window = createMyWindow(width, height);
    sfTexture *texture = sfTexture_createFromFile("ressources/EndScreen.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfMouseButtonEvent event;
    sfVector2f size;

    size.x = 2;
    size.y = 2;
    sfSprite_setScale(sprite, size);
    sfRenderWindow_setFramerateLimit(window, 40);
    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        while (sfRenderWindow_pollEvent(window, &event) && EVENT(window, event) != 0)
            return (2 + EVENT(window, event));
        sfRenderWindow_display(window);
    }
}
