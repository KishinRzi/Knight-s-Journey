#include "player.h"
#include "enemy.h"
#include <stdlib.h>
#include <stdio.h>

#define FRAME_WIDTH 64
#define FRAME_HEIGHT 64
#define RUN_LINE_INDEX 10  // Ligne "Run" dans la spritesheet
#define RUN_FRAMES 6       // Nombre de frames dans la ligne
#define ANIM_SPEED 0.1f    // Temps entre les frames (en secondes)

player_t *create_player(const char *filepath)
{
    player_t *player = malloc(sizeof(player_t));
    if (!player)
        return NULL;

    player->texture = sfTexture_createFromFile(filepath, NULL);
    if (!player->texture) {
        printf("Erreur : impossible de charger %s\n", filepath);
        free(player);
        return NULL;
    } else {
        printf("Image %s chargée avec succès\n", filepath);
    }

    player->sprite = sfSprite_create();
    player->position = (sfVector2f){100, 100};
    player->speed = 4.0f;
    player->frame_index = 0;
    player->frame_timer = 0;
    player->hp = 100;
    player->stamina = 100;
    player->attack_cooldown = 0.f;


    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfIntRect rect = {0, RUN_LINE_INDEX * FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT};
    sfSprite_setTextureRect(player->sprite, rect);
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setScale(player->sprite, (sfVector2f){4.0f, 4.0f});

    return player;
}

void move_player(player_t *player, float delta_time)
{
    int moving = 0;
    sfVector2f scale = sfSprite_getScale(player->sprite);

    if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->position.x -= player->speed;
        scale.x = -4.0f; // flip horizontal
        moving = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD)) {
        player->position.x += player->speed;
        scale.x = 4.0f; // face normale
        moving = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ)) {
        player->position.y -= player->speed;
        moving = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS)) {
        player->position.y += player->speed;
        moving = 1;
    }
    if (player->attack_cooldown > 0)
    player->attack_cooldown -= delta_time;


    sfSprite_setScale(player->sprite, scale);

    if (moving) {
        player->frame_timer += delta_time;
        if (player->frame_timer >= ANIM_SPEED) {
            player->frame_index = (player->frame_index + 1) % RUN_FRAMES;
            sfIntRect rect = {
                player->frame_index * FRAME_WIDTH,
                RUN_LINE_INDEX * FRAME_HEIGHT,
                FRAME_WIDTH,
                FRAME_HEIGHT
            };
            sfSprite_setTextureRect(player->sprite, rect);
            player->frame_timer = 0;
        }
    }

    sfSprite_setPosition(player->sprite, player->position);
}

void draw_player(sfRenderWindow *window, player_t *player)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    free(player);
}

int player_attack(player_t *player, enemy_t *enemy)
{
    if (!enemy->is_alive || player->stamina < 20 || player->attack_cooldown > 0)
        return 0;

    sfFloatRect p = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect e = sfSprite_getGlobalBounds(enemy->sprite);

    if (sfFloatRect_intersects(&p, &e, NULL)) {
        enemy->hp -= 30;
        player->stamina -= 20;
        player->attack_cooldown = 0.5f; // demi seconde de cooldown
        if (enemy->hp <= 0) enemy->is_alive = 0;
        return 1;
    }
    return 0;
}
