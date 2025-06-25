#include "../../include/my_rpg.h"

static void handle_combat_keypressed(rpg_t *rpg)
{

}

void handle_combat_event(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (rpg->event.type == sfEvtKeyPressed)
            handle_combat_keypressed(rpg);
    }
}