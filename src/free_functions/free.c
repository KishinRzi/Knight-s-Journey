/*
** EPITECH PROJECT, 2023
** destroy all
** File description:
** function to destroy all memory allocated elements
*/

#include "../../include/my_rpg.h"

void free_unit(unit_t *unit)
{
    if (!unit)
        return;
    if (unit->sprite)
        sfSprite_destroy(unit->sprite);
    if (unit->clock)
        sfClock_destroy(unit->clock);
    free(unit);
}

void free_multiple_units(unit_t **units)
{
    if (units) {
        for (int i = 0; units[i]; i++)
            free_unit(units[i]);
        free(units);
    }
}

void free_combat_gui(combat_gui_t *combat_gui)
{
    if (!combat_gui)
        return;
    if (!combat_gui->frame_sprite)
        sfSprite_destroy(combat_gui->frame_sprite);
}

void free_combat(combat_t *combat)
{
    if (!combat)
        return;
    if (combat->enemies) {
        free_multiple_units(combat->enemies);
    }
    if (combat->player)
        free_unit(combat->player);
    if (combat->combat_gui)
        free_combat_gui(combat->combat_gui);
    if (combat->background)
        sfSprite_destroy(combat->background);
    free(combat);
}

void free_rpg(rpg_t *rpg)
{
    if (!rpg)
        return;
    if (rpg->window)
        sfRenderWindow_destroy(rpg->window);
    free_unit(rpg->player);
    if (rpg->keybinds)
        free(rpg->keybinds);
    free_combat(rpg->combat);
    if (rpg->clock)
        sfClock_destroy(rpg->clock);
    get_texture(NULL);
    free(rpg);
}
