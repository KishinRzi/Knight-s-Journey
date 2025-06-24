/*
** EPITECH PROJECT, 2023
** destroy all
** File description:
** function to destroy all memory allocated elements
*/

#include "../../include/my_rpg.h"

void handle_keypressed(rpg_t *rpg)
{
    if (rpg->event.key.code == rpg->keybinds->up)
        move_unit(rpg->player, rpg->clock, MOVE_UP);
    if (rpg->event.key.code == rpg->keybinds->left)
        move_unit(rpg->player, rpg->clock, MOVE_LEFT);
    if (rpg->event.key.code == rpg->keybinds->down)
        move_unit(rpg->player, rpg->clock, MOVE_DOWN);
    if (rpg->event.key.code == rpg->keybinds->right)
        move_unit(rpg->player, rpg->clock, MOVE_RIGHT);
    if ((rpg->event.key.code == rpg->keybinds->up ||
        rpg->event.key.code == rpg->keybinds->left ||
        rpg->event.key.code == rpg->keybinds->down ||
        rpg->event.key.code == rpg->keybinds->right) &&
        rpg->player->rect.left == 0)
        is_combat(rpg);
}

void handle_event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (rpg->event.type == sfEvtKeyPressed)
            handle_keypressed(rpg);
        if (rpg->event.type == sfEvtKeyReleased) {
            reset_player_animation(rpg->player);
        }
    }
}
