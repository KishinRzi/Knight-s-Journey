/*
** EPITECH PROJECT, 2023
** start_paint
** File description:
** function to initiate the program window
*/

#include "../../include/my_rpg.h"

void display_unit(sfRenderWindow *window, unit_t *unit)
{
    if (unit->animation)
        unit->animation(unit);
    sfRenderWindow_drawSprite(window, unit->sprite, NULL);
}
