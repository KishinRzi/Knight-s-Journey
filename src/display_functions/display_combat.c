#include "../../include/my_rpg.h"

void display_combat_gui(sfRenderWindow *window, combat_gui_t *combat_gui)
{
    sfRenderWindow_drawSprite(window, combat_gui->frame_sprite, NULL);
}

void display_combat(rpg_t *rpg)
{
    for (int i = 0; rpg->combat->enemies[i]; i++)
            display_unit(rpg->window, rpg->combat->enemies[i]);
    display_unit(rpg->window, rpg->combat->player);
    display_combat_gui(rpg->window, rpg->combat->combat_gui);
    display_window(rpg->window);
}