/*
** EPITECH PROJECT, 2023
** destroy all
** File description:
** function to destroy all memory allocated elements
*/

#include "../../include/my_rpg.h"

void move_up(unit_t *unit, sfClock *clock)
{
    sfVector2f pos;
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100.0;
    pos = sfSprite_getPosition(unit->sprite);
    pos.y -= unit->speed * seconds;
    sfSprite_setPosition(unit->sprite, pos);
}

void move_left(unit_t *unit, sfClock *clock)
{
    sfVector2f pos;
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100.0;
    pos = sfSprite_getPosition(unit->sprite);
    pos.x -= unit->speed * seconds;
    sfSprite_setPosition(unit->sprite, pos);
}

void move_down(unit_t *unit, sfClock *clock)
{
    sfVector2f pos;
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100.0;
    pos = sfSprite_getPosition(unit->sprite);
    pos.y += unit->speed * seconds;
    sfSprite_setPosition(unit->sprite, pos);
}

void move_right(unit_t *unit, sfClock *clock)
{
    sfVector2f pos;
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 100.0;
    pos = sfSprite_getPosition(unit->sprite);
    pos.x += unit->speed * seconds;
    sfSprite_setPosition(unit->sprite, pos);
}

void move_unit(unit_t *unit, sfClock *clock, int movement)
{
    int move[5] = {MOVE_UP, MOVE_LEFT, MOVE_DOWN, MOVE_RIGHT, 0};
    void (*movement_function[])(unit_t *, sfClock *) = {
        move_up, move_left, move_down, move_right, NULL};
    void (*animation_function[])(unit_t *) = {
        up_animation, left_animation, down_animation, right_animation, 0};

    if (!unit)
        return;
    for (int i = 0; move[i]; i++) {
        if (move[i] == movement) {
            unit->animation = animation_function[i];
            movement_function[i](unit, clock);
            return;
        }
    }
}
