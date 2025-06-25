#include "../../include/my_rpg.h"

void display_unit(sfRenderWindow *window, unit_t *unit)
{
    if (unit->animation)
        unit->animation(unit);
    sfRenderWindow_drawSprite(window, unit->sprite, NULL);
}
