/*
** EPITECH PROJECT, 2023
** start_paint
** File description:
** function to initiate the program window
*/

#include "../../include/my_rpg.h"

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}
