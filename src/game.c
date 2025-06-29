#include "game.h"
#include "player.h"

static player_t *player = NULL;

void update_game(sfRenderWindow *window, sfClock *clock)
{
    static int initialized = 0;
    if (!initialized) {
        player = create_player("assets/Warrior-V1.3/Warrior/SpriteSheet/Warrior_Sheet-Effect.png");
        initialized = 1;
    }

    sfTime time = sfClock_restart(clock);
    float delta_time = sfTime_asSeconds(time);

    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }

    move_player(player, delta_time);
    sfRenderWindow_clear(window, sfColor_fromRGB(20, 20, 80));
    draw_player(window, player);
    sfRenderWindow_display(window);
}
