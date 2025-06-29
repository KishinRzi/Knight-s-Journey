#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.h>
#include "enemy.h"

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    float speed;
    int frame_index;
    float frame_timer;
    int hp;
    int stamina;
    float attack_cooldown;
} player_t;

player_t *create_player(const char *filepath);
void move_player(player_t *player, float delta_time);
void draw_player(sfRenderWindow *window, player_t *player);
void destroy_player(player_t *player);
int player_attack(player_t *player, enemy_t *enemy);

#endif 
