/*
** EPITECH PROJECT, 2018
** bullet.c
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

#include "include/proto.h"
#include "include/my.h"

void disp(sfRenderWindow *window, float x, float y)
{
    sfTexture *tbullet = sfTexture_createFromFile("sprite_bullet.png", NULL);
    sfSprite *sbullet = sfSprite_create();
    sfVector2f where;
    sfVector2f size;
    sfIntRect rect;
    
    where.x = x;
    where.y = y;
    size.x = 2;
    size.y = 2;
    
    sfSprite_setScale(sbullet, size);
    sfSprite_setTexture(sbullet, tbullet, sfTrue);
    sfSprite_setPosition(sbullet, where);
    sfRenderWindow_drawSprite(window, sbullet, NULL);
    }
 
void display_bullet(sfRenderWindow *window, int bullet, int width, int height)
{
    
    switch (bullet) {
    case 10: disp(window, 1, 1);
    case 9: disp(window, 30, 1);
    case 8: disp(window, 60, 1);
    case 7: disp(window, 90, 1);
    case 6: disp(window, 120, 1);
    case 5: disp(window, 150, 1);
    case 4: disp(window, 180, 1);
    case 3: disp(window, 210, 1);
    case 2: disp(window, 240, 1);
    case 1: disp(window, 270, 1);
    case 0: disp(window, 300, 1);
    }
}
