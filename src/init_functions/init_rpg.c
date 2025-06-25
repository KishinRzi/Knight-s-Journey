#include "../../include/my_rpg.h"

static sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WIND_W, WIND_H, 32};
    return sfRenderWindow_create(mode, "Knight's Journey", sfResize | sfClose, NULL);
}

unit_t *create_hero_combat(char *path, int hp)
{
    unit_t *player = malloc(sizeof(unit_t));
    if (!player) return NULL;

    set_unit_null(player);

    player->texture = get_texture(path);
    if (!player->texture) { free_unit(player); return NULL; }

    player->clock = sfClock_create();
    player->rect = (sfIntRect){0, 0, HERO_SIZE_W, HERO_SIZE_H};

    player->sprite = sfSprite_create();
    if (!player->sprite) { free_unit(player); return NULL; }

    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){HERO_SIZE_W/2, HERO_SIZE_H/2});
    player->pos = (sfVector2f){WIND_W/2, WIND_H/2};
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){-6, 6});
    player->speed = 20;
    player->hp = hp;
    player->animation = static_animation_hero;
    return player;
}

unit_t *create_unit(char *path, int hp)
{
    unit_t *player = malloc(sizeof(unit_t));
    if (!player) return NULL;

    set_unit_null(player);

    player->texture = get_texture(path);
    if (!player->texture) { free_unit(player); return NULL; }

    player->clock = sfClock_create();
    player->rect = (sfIntRect){0, UNIT_SIZE * 2, UNIT_SIZE, UNIT_SIZE};

    player->sprite = sfSprite_create();
    if (!player->sprite) { free_unit(player); return NULL; }

    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){UNIT_SIZE/2, UNIT_SIZE/2});
    player->pos = (sfVector2f){WIND_W/2, WIND_H/2};
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){2, 2});
    player->speed = 20;
    player->hp = hp;
    player->animation = static_animation;
    return player;
}

static keybind_t *create_keybinds(void)
{
    keybind_t *keybinds = malloc(sizeof(keybind_t));
    if (!keybinds) return NULL;
    keybinds->up = sfKeyZ;
    keybinds->left = sfKeyQ;
    keybinds->down = sfKeyS;
    keybinds->right = sfKeyD;
    return keybinds;
}

static combat_gui_t *create_combat_gui(void)
{
    combat_gui_t *gui = malloc(sizeof(combat_gui_t));
    if (!gui) return NULL;

    set_combat_gui_null(gui);

    gui->frame_texture = get_texture(CBT_FRAME);
    if (!gui->frame_texture) { free_combat_gui(gui); return NULL; }

    gui->frame_sprite = sfSprite_create();
    if (!gui->frame_sprite) { free_combat_gui(gui); return NULL; }

    gui->frame_rect = (sfIntRect){0, 0, FRAME_SIZE, FRAME_SIZE};
    sfSprite_setTexture(gui->frame_sprite, gui->frame_texture, sfFalse);
    sfSprite_setTextureRect(gui->frame_sprite, gui->frame_rect);
    sfSprite_setOrigin(gui->frame_sprite, (sfVector2f){FRAME_SIZE/2, FRAME_SIZE/2});
    sfSprite_setPosition(gui->frame_sprite, (sfVector2f){WIND_W/2 + 800, WIND_H/2});
    sfSprite_setScale(gui->frame_sprite, (sfVector2f){2.5, 4});
    return gui;
}

static combat_t *create_combat(void)
{
    combat_t *combat = malloc(sizeof(combat_t));
    if (!combat) return NULL;

    set_combat_null(combat);

    combat->background = sfSprite_create();
    if (!combat->background) { free(combat); return NULL; }

    sfTexture *bg = get_texture(CBT_BACKGROUND);
    if (!bg) { sfSprite_destroy(combat->background); free(combat); return NULL; }
    sfSprite_setTexture(combat->background, bg, sfFalse);

    combat->combat_gui = create_combat_gui();
    if (!combat->combat_gui) {
        sfSprite_destroy(combat->background);
        free(combat);
        return NULL;
    }

    combat->player = create_hero_combat(CBT_HERO_PATH, 100);
    if (!combat->player) {
        free_combat_gui(combat->combat_gui);
        sfSprite_destroy(combat->background);
        free(combat);
        return NULL;
    }

    return combat;
}

rpg_t *init_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    if (!rpg) return NULL;

    set_rpg_null(rpg);

    rpg->window = create_window();
    if (!rpg->window) { free(rpg); return NULL; }

    rpg->player = create_unit(HERO_PATH, 100);
    if (!rpg->player) { sfRenderWindow_destroy(rpg->window); free(rpg); return NULL; }

    rpg->keybinds = create_keybinds();
    if (!rpg->keybinds) {
        free_unit(rpg->player);
        sfRenderWindow_destroy(rpg->window);
        free(rpg);
        return NULL;
    }

    rpg->clock = sfClock_create();
    if (!rpg->clock) {
        free_unit(rpg->player);
        free(rpg->keybinds);
        sfRenderWindow_destroy(rpg->window);
        free(rpg);
        return NULL;
    }

    rpg->combat = create_combat();
    if (!rpg->combat) {
        free_unit(rpg->player);
        free(rpg->keybinds);
        sfClock_destroy(rpg->clock);
        sfRenderWindow_destroy(rpg->window);
        free(rpg);
        return NULL;
    }

    rpg->is_combat = false;
    return rpg;
}
