// src/main.c
#include <SFML/Graphics.h>
#include "game.h"

int main(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Knight's Journey", sfResize | sfClose, NULL);
    sfClock *clock = sfClock_create();

    if (!window)
        return 84;

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);

        update_game(window, clock);  // apl le moteur de jeu

        sfRenderWindow_display(window);
    }

    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
