#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.h>

typedef struct enemy_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    int hp;
    float speed;
    int is_alive;
} enemy_t;

enemy_t *init_enemy(const char *texture_path, sfVector2f pos);
void update_enemy(enemy_t *enemy, sfVector2f player_pos, float delta_time);
void draw_enemy(sfRenderWindow *window, enemy_t *enemy);
void destroy_enemy(enemy_t *enemy);

#endif
