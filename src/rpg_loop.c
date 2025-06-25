#include "../include/my_rpg.h"

bool start_game(void)
{
    rpg_t *rpg = init_rpg();

    if (!rpg)
        return false;
    while (sfRenderWindow_isOpen(rpg->window)) {
        sfClock_restart(rpg->clock);
        handle_event(rpg);
        display_unit(rpg->window, rpg->player);
        display_window(rpg->window);
    }
    free_rpg(rpg);
    return true;
}
