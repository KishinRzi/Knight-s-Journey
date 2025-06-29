#include "game.h"
#include "player.h"
#include "hud.h"
#include "enemy.h"

static player_t *player = NULL;
static hud_t *hud = NULL;

void update_game(sfRenderWindow *window, sfClock *clock)
{
    static enemy_t *enemy = NULL;
    static int initialized = 0;

    if (!initialized) {
        player = create_player("assets/Warrior-V1.3/Warrior/SpriteSheet/Warrior_Sheet-Effect.png");
        hud = init_hud();
        initialized = 1;
    }

    sfTime time = sfClock_restart(clock);
    float delta_time = sfTime_asSeconds(time);

    if (!enemy) {
        enemy = init_enemy("assets/Warrior-V1.3/Warrior/SpriteSheet/Warrior_Sheet-Effect.png", (sfVector2f){200, 300});
        if (!enemy)
            return;
    }

    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }

    move_player(player, delta_time);
    update_enemy(enemy, player->position, delta_time);

    if (sfKeyboard_isKeyPressed(sfKeySpace) || sfMouse_isButtonPressed(sfMouseLeft))
        player_attack(player, enemy);

    update_hud(hud, player);

    sfRenderWindow_clear(window, sfColor_fromRGB(20, 20, 80));
    draw_player(window, player);
    draw_enemy(window, enemy);
    draw_hud(window, hud);
    sfRenderWindow_display(window);
}
