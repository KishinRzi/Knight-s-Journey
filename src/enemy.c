#include "enemy.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

enemy_t *init_enemy(const char *texture_path, sfVector2f pos)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    if (!enemy)
        return NULL;

    enemy->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!enemy->texture) {
        printf("Erreur : image %s introuvable\n", texture_path);
        free(enemy);
        return NULL;
    }

    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setPosition(enemy->sprite, pos);
    enemy->position = pos;
    enemy->hp = 100;
    enemy->speed = 80.0f;
    enemy->is_alive = 1;
    return enemy;
}

void update_enemy(enemy_t *enemy, sfVector2f player_pos, float dt)
{
    if (!enemy || !enemy->is_alive) return;

    sfVector2f dir = {
        player_pos.x - enemy->position.x,
        player_pos.y - enemy->position.y
    };
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 1) {
        dir.x /= len;
        dir.y /= len;
        enemy->position.x += dir.x * enemy->speed * dt;
        enemy->position.y += dir.y * enemy->speed * dt;
        sfSprite_setPosition(enemy->sprite, enemy->position);
    }
}

void draw_enemy(sfRenderWindow *window, enemy_t *enemy)
{
    if (enemy && enemy->is_alive)
        sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
}

void destroy_enemy(enemy_t *enemy)
{
    if (!enemy) return;
    sfTexture_destroy(enemy->texture);
    sfSprite_destroy(enemy->sprite);
    free(enemy);
}
