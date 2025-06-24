/*
** EPITECH PROJECT, 2023
** destroy all
** File description:
** function to destroy all memory allocated elements
*/

#include "../../include/my_rpg.h"

static void place_enemies(unit_t **enemies, int nb_enemies)
{
    if (nb_enemies == 1) {
        sfSprite_setPosition(enemies[0]->sprite, (sfVector2f){WIND_H /2 - 700, WIND_W / 2});
        enemies[0]->pos = sfSprite_getPosition(enemies[0]->sprite);
    }
    if (nb_enemies == 2) {
        sfSprite_setPosition(enemies[0]->sprite, (sfVector2f){WIND_H / 2 - 700, WIND_W / 2 + 200});
        enemies[0]->pos = sfSprite_getPosition(enemies[0]->sprite);
        sfSprite_setPosition(enemies[1]->sprite, (sfVector2f){WIND_H / 2 - 700, WIND_W / 2 - 200});
        enemies[1]->pos = sfSprite_getPosition(enemies[1]->sprite);
    }
    if (nb_enemies == 3) {
        sfSprite_setPosition(enemies[0]->sprite, (sfVector2f){WIND_H / 2 - 700, WIND_W / 2 + 200});
        enemies[0]->pos = sfSprite_getPosition(enemies[0]->sprite);
        sfSprite_setPosition(enemies[1]->sprite, (sfVector2f){WIND_H / 2 - 700, WIND_W / 2});
        enemies[1]->pos = sfSprite_getPosition(enemies[0]->sprite);
        sfSprite_setPosition(enemies[2]->sprite, (sfVector2f){WIND_H / 2 - 700, WIND_W / 2 - 200});
        enemies[2]->pos = sfSprite_getPosition(enemies[1]->sprite);
    }
}

static unit_t **init_enemies(void)
{
    int nb_enemies = rand() % 3 + 1;
    unit_t **enemies = malloc(sizeof(unit_t *) * (nb_enemies + 1));

    if (!enemies)
        return NULL;
    printf("nb enemies: %d\n", nb_enemies);
    enemies[nb_enemies] = NULL;
    for (int i = 0; i < nb_enemies; i++) {
        enemies[i] = create_unit(ENEMY_PATH, 30);
        if (!enemies[i])
            exit(84);
    }
    place_enemies(enemies, nb_enemies);
    return enemies;
}

static void get_player_stats(unit_t *cbt_player, unit_t *rpg_player)
{
    cbt_player->hp = rpg_player->hp;
}

static void start_combat(rpg_t *rpg)
{
    rpg->combat->enemies = init_enemies();
    if (!rpg->combat->enemies) {
        free_rpg(rpg);
        exit(84);
    }
    get_player_stats(rpg->combat->player, rpg->player);
    combat_loop(rpg);
    free_multiple_units(rpg->combat->enemies);
    rpg->combat = NULL;
}

void is_combat(rpg_t *rpg)
{
    int random = 0;

    if (!rpg->is_combat)
        return;
    random = rand() % 100 + 1;
    printf("%d\n", random);
    if (random < 10)
        start_combat(rpg);
}
