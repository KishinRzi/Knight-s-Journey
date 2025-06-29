#include "hud.h"
#include <stdlib.h>

hud_t *init_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->health_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->health_bar, (sfVector2f){200, 20});
    sfRectangleShape_setFillColor(hud->health_bar, sfRed);
    sfRectangleShape_setPosition(hud->health_bar, (sfVector2f){20, 20});

    hud->stamina_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->stamina_bar, (sfVector2f){200, 20});
    sfRectangleShape_setFillColor(hud->stamina_bar, sfGreen);
    sfRectangleShape_setPosition(hud->stamina_bar, (sfVector2f){20, 50});

    return hud;
}

void update_hud(hud_t *hud, player_t *player)
{
    float hp_ratio = (float)player->hp / 100.0f;
    float stamina_ratio = (float)player->stamina / 100.0f;

    sfRectangleShape_setSize(hud->health_bar, (sfVector2f){200 * hp_ratio, 20});
    sfRectangleShape_setSize(hud->stamina_bar, (sfVector2f){200 * stamina_ratio, 20});
}

void draw_hud(sfRenderWindow *window, hud_t *hud)
{
    sfRenderWindow_drawRectangleShape(window, hud->health_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, hud->stamina_bar, NULL);
}

void destroy_hud(hud_t *hud)
{
    sfRectangleShape_destroy(hud->health_bar);
    sfRectangleShape_destroy(hud->stamina_bar);
    free(hud);
}
