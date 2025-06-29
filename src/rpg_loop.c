#include "../include/my_rpg.h"

void rpg_loop(rpg_t *rpg)
{
    sfTime delta;
    float seconds;

    while (sfRenderWindow_isOpen(rpg->window)) {
        delta = sfClock_restart(rpg->clock);
        seconds = sfTime_asSeconds(delta);
        (void)seconds;

        handle_event(rpg);

        sfRenderWindow_clear(rpg->window, sfColor_fromRGB(80, 80, 80)); // fond gris clair

        if (rpg->is_combat) {
            combat_loop(rpg);
        } else {
            display_window(rpg->window);
            display_unit(rpg->window, rpg->player); // animation incluse ici
        }

        sfRenderWindow_display(rpg->window);
    }
}
