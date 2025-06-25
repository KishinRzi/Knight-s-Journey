#include "../include/my_rpg.h"

void free_unit(unit_t *unit)
{
    if (!unit) return;
    if (unit->sprite) sfSprite_destroy(unit->sprite);
    if (unit->texture) sfTexture_destroy(unit->texture);
    if (unit->clock) sfClock_destroy(unit->clock);
    free(unit);
}

void free_combat_gui(combat_gui_t *gui)
{
    if (!gui) return;
    if (gui->frame_sprite) sfSprite_destroy(gui->frame_sprite);
    if (gui->frame_texture) sfTexture_destroy(gui->frame_texture);
    free(gui);
}

void free_combat(combat_t *combat)
{
    if (!combat) return;
    if (combat->background) sfSprite_destroy(combat->background);
    if (combat->combat_gui) free_combat_gui(combat->combat_gui);
    if (combat->player) free_unit(combat->player);
    // Si tu ajoutes enemies plus tard : free_multiple_units(combat->enemies);
    free(combat);
}

void free_rpg(rpg_t *rpg)
{
    if (!rpg) return;
    if (rpg->combat) free_combat(rpg->combat);
    if (rpg->player) free_unit(rpg->player);
    if (rpg->keybinds) free(rpg->keybinds);
    if (rpg->clock) sfClock_destroy(rpg->clock);
    if (rpg->window) sfRenderWindow_destroy(rpg->window);
    free(rpg);
}
