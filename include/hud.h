#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.h>
#include "player.h"

typedef struct hud_s {
    sfRectangleShape *health_bar;
    sfRectangleShape *stamina_bar;
} hud_t;

hud_t *init_hud(void);
void update_hud(hud_t *hud, player_t *player);
void draw_hud(sfRenderWindow *window, hud_t *hud);
void destroy_hud(hud_t *hud);

#endif
