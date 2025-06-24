/*
** EPITECH PROJECT, 2023
** my_rpg.h
** File description:
** header file for my_rpg program
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#ifndef MYRPG_H
    #define MYRPG_H

    #define WIND_W 1080
    #define WIND_H 1920
    #define UNIT_SIZE 64
    #define HERO_SIZE_W 414 / 6
    #define HERO_SIZE_H 748 / 17
    #define FRAME_SIZE 400 / 3

    #define MOVE_UP 1
    #define MOVE_LEFT 2
    #define MOVE_DOWN 3
    #define MOVE_RIGHT 4


    #define HERO_PATH "assets/main_char.png"
    #define ENEMY_PATH "assets/asian_female.png"
    #define CBT_HERO_PATH "assets/Warrior-V1.3/Warrior/SpriteSheet/Warrior_Sheet-Effect.png"
    #define CBT_BACKGROUND "assets/fight_background.png"
    #define CBT_FRAME "assets/cbt_frame.png"

typedef struct texture_s {
    char *name;
    char *path;
    sfTexture *texture;
    struct texture_s *next;
} texture_t;

typedef struct unit_s {
    float speed;
    int hp;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    void (*animation)(struct unit_s *unit);
} unit_t;

typedef struct keybind_s {
    sfKeyCode up;
    sfKeyCode left;
    sfKeyCode down;
    sfKeyCode right;
} keybind_t;

typedef struct combat_gui_s {
    sfTexture *frame_texture;
    sfSprite *frame_sprite;
    sfIntRect frame_rect;
} combat_gui_t;

typedef struct combat_s {
    unit_t **enemies;
    unit_t *player;
    sfSprite *background;
    combat_gui_t *combat_gui;
} combat_t;

typedef struct rpg_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
    unit_t *player;
    keybind_t *keybinds;
    combat_t *combat;
    bool is_combat;
} rpg_t;

rpg_t *init_rpg(void);
sfTexture *get_texture(char *str);
unit_t *create_unit(char *path, int hp);
void move_unit(unit_t *player, sfClock *clock, int movement);
void up_animation(unit_t *unit);
void left_animation(unit_t *unit);
void down_animation(unit_t *unit);
void right_animation(unit_t *unit);
void static_animation(unit_t *unit);
void static_animation_hero(unit_t *unit);
void reset_player_animation(unit_t *unit);
bool start_game(void);
void handle_event(rpg_t *rpg);
void is_combat(rpg_t *rpg);
void combat_loop(rpg_t *rpg);
void handle_combat_event(rpg_t *rpg);
void display_unit(sfRenderWindow *window, unit_t *unit);
void display_window(sfRenderWindow *window);
void display_combat(rpg_t *rpg);
void free_rpg(rpg_t *rpg);
void free_unit(unit_t *unit);
void free_combat(combat_t *combat);
void free_multiple_units(unit_t **units);
void free_combat_gui(combat_gui_t *combat_gui);
#endif
