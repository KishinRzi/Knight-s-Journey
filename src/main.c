#include <SFML/Graphics.h>
#include "game.h"

int main(void)
{
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Knight's Journey", sfResize | sfClose, NULL);
    sfClock *clock = sfClock_create();

    if (!window || !clock)
        return 84;

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        update_game(window, clock);  // tout est géré ici
    }

    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
