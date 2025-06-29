// src/game.c
#include <SFML/Graphics.h>
#include "game.h"

void update_game(sfRenderWindow *window, sfClock *clock)
{
    // Exemple de fond (bientôt remplacé par la map)
    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape_setSize(background, (sfVector2f){1280, 720});
    sfRectangleShape_setFillColor(background, sfColor_fromRGB(30, 30, 40));

    sfRenderWindow_drawRectangleShape(window, background, NULL);
    sfRectangleShape_destroy(background);
}
