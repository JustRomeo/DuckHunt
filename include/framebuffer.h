/*
** EPITECH PROJECT, 2018
** framebuffer.h
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

typedef struct framer 
{ 
    unsigned char *pixels; 
    unsigned int width; 
    unsigned int height;
} framer_t; 

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;
