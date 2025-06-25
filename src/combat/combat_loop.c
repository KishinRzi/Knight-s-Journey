#include "../../include/my_rpg.h"

void combat_loop(rpg_t *rpg)
{
    while (rpg->combat->enemies && sfRenderWindow_isOpen(rpg->window)) {
        // sfRenderWindow_drawSprite(rpg->window, rpg->combat->background, NULL);
        handle_combat_event(rpg);
        display_combat(rpg);
    }
}
