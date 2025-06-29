#include "../../include/my_rpg.h"

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);

    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){100, 100});
    sfRectangleShape_setFillColor(rect, sfRed);
    sfRectangleShape_setPosition(rect, (sfVector2f){200, 200});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);

    // autres draw : sprites, texte...
}
