#include "../../include/my_rpg.h"

void up_animation(unit_t *unit)
{
    sfTime time;
    float seconds;
    static sfIntRect rect = (sfIntRect){0, UNIT_SIZE * 8, UNIT_SIZE, UNIT_SIZE};

    if (unit->rect.top != UNIT_SIZE * 8)
        unit->rect = rect;
    time = sfClock_getElapsedTime(unit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (unit->rect.left == UNIT_SIZE * 7)
            unit->rect.left = 0;
        else
            unit->rect.left += UNIT_SIZE;
        sfSprite_setTextureRect(unit->sprite, unit->rect);
        sfClock_restart(unit->clock);
    }
}

void left_animation(unit_t *unit)
{
    sfTime time;
    float seconds;
    static sfIntRect rect = (sfIntRect){0, UNIT_SIZE * 9, UNIT_SIZE, UNIT_SIZE};

    if (unit->rect.top != UNIT_SIZE * 9)
        unit->rect = rect;
    time = sfClock_getElapsedTime(unit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (unit->rect.left == UNIT_SIZE * 7)
            unit->rect.left = 0;
        else
            unit->rect.left += UNIT_SIZE;
        sfSprite_setTextureRect(unit->sprite, unit->rect);
        sfClock_restart(unit->clock);
    }
}

void down_animation(unit_t *unit)
{
    sfTime time;
    float seconds;
    sfIntRect rect = (sfIntRect){0, UNIT_SIZE * 10, UNIT_SIZE, UNIT_SIZE};

    if (unit->rect.top != UNIT_SIZE * 10)
        unit->rect = rect;
    time = sfClock_getElapsedTime(unit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (unit->rect.left == UNIT_SIZE * 7)
            unit->rect.left = 0;
        else
            unit->rect.left += UNIT_SIZE;
        sfSprite_setTextureRect(unit->sprite, unit->rect);
        sfClock_restart(unit->clock);
    }
}

void right_animation(unit_t *unit)
{
    sfTime time;
    float seconds;
    sfIntRect rect = (sfIntRect){0, UNIT_SIZE * 11, UNIT_SIZE, UNIT_SIZE};

    if (unit->rect.top != UNIT_SIZE * 11)
        unit->rect = rect;
    time = sfClock_getElapsedTime(unit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (unit->rect.left == UNIT_SIZE * 7)
            unit->rect.left = 0;
        else
            unit->rect.left += UNIT_SIZE;
        sfSprite_setTextureRect(unit->sprite, unit->rect);
        sfClock_restart(unit->clock);
    }
}

void static_animation(unit_t *unit)
{
    sfTime time;
    float seconds;
    sfIntRect rect = (sfIntRect){0, UNIT_SIZE * 2, UNIT_SIZE, UNIT_SIZE};

    if (unit->rect.top != UNIT_SIZE * 2)
        unit->rect = rect;
    time = sfClock_getElapsedTime(unit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (unit->rect.left == UNIT_SIZE * 6)
            unit->rect.left = 0;
        else
            unit->rect.left += UNIT_SIZE;
        sfSprite_setTextureRect(unit->sprite, unit->rect);
        sfClock_restart(unit->clock);
    }
}

void reset_player_animation(unit_t *unit)
{
    unit->animation = NULL;
    unit->rect.left = 0;
    sfSprite_setTextureRect(unit->sprite, unit->rect);
}

void static_animation_hero(unit_t *unit)
{
    sfTime time;
    float seconds;
    sfIntRect rect = (sfIntRect){0, 0, HERO_SIZE_W, HERO_SIZE_H};

    if (unit->rect.top != HERO_SIZE_H * 0)
        unit->rect = rect;
    time = sfClock_getElapsedTime(unit->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (unit->rect.left == HERO_SIZE_W * 5)
            unit->rect.left = 0;
        else
            unit->rect.left += HERO_SIZE_W;
        sfSprite_setTextureRect(unit->sprite, unit->rect);
        sfClock_restart(unit->clock);
    }
}
