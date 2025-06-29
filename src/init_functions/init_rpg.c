#include "../../include/my_rpg.h"

static sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode = {WIND_H, WIND_W, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "my_rpg", sfDefaultStyle, NULL);
    return window;
}

static void set_unit_null(unit_t *unit)
{
    if (!unit)
        return;
    unit->animation = NULL;
    unit->clock = NULL;
    unit->hp = 0;
    unit->pos = (sfVector2f){0, 0};
    unit->rect = (sfIntRect){0, 0, 0, 0};
    unit->speed = 0;
    unit->sprite = NULL;
    unit->texture = NULL;
}

unit_t *create_hero_combat(char *path, int hp)
{
    unit_t *player = malloc(sizeof(unit_t));
    if (!player)
        return NULL;

    set_unit_null(player);
    player->texture = get_texture(path);
    if (!player->texture) {
        free_unit(player);
        return NULL;
    }

    player->clock = sfClock_create();
    player->rect = (sfIntRect){0, 0, HERO_SIZE_W, HERO_SIZE_H};
    player->sprite = sfSprite_create();
    if (!player->sprite) {
        free_unit(player);
        return NULL;
    }

    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){HERO_SIZE_W / 2, HERO_SIZE_H / 2});
    player->pos = (sfVector2f){WIND_W / 2, WIND_H / 2};
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){2, 2});

    player->speed = 20;
    player->hp = hp;
    player->animation = static_animation_hero;
    return player;
}

unit_t *create_unit(char *path, int hp)
{
    unit_t *player = malloc(sizeof(unit_t));
    if (!player)
        return NULL;

    set_unit_null(player);
    player->texture = get_texture(path);
    if (!player->texture) {
        printf("Texture introuvable : %s\n", path);
        free_unit(player);
        return NULL;
    }

    player->clock = sfClock_create();
    player->rect = (sfIntRect){0, 0, HERO_SIZE_W, HERO_SIZE_H};
    player->sprite = sfSprite_create();
    if (!player->sprite) {
        free_unit(player);
        return NULL;
    }

    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){HERO_SIZE_W / 2, HERO_SIZE_H / 2});
    player->pos = (sfVector2f){WIND_W / 2, WIND_H / 2};
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
    if (!keybinds)
        return NULL;

    keybinds->up = sfKeyZ;
    keybinds->left = sfKeyQ;
    keybinds->down = sfKeyS;
    keybinds->right = sfKeyD;
    return keybinds;
}

static void set_combat_gui_null(combat_gui_t *combat_gui)
{
    if (!combat_gui)
        return;
    combat_gui->frame_rect = (sfIntRect){0, 0, 0, 0};
    combat_gui->frame_sprite = NULL;
    combat_gui->frame_texture = NULL;
}

static combat_gui_t *create_combat_gui(void)
{
    combat_gui_t *combat_gui = malloc(sizeof(combat_gui_t));
    if (!combat_gui)
        return NULL;

    set_combat_gui_null(combat_gui);
    combat_gui->frame_texture = get_texture(CBT_FRAME);
    if (!combat_gui->frame_texture) {
        free_combat_gui(combat_gui);
        return NULL;
    }

    combat_gui->frame_sprite = sfSprite_create();
    if (!combat_gui->frame_sprite) {
        free_combat_gui(combat_gui);
        return NULL;
    }

    combat_gui->frame_rect = (sfIntRect){FRAME_SIZE * 0, FRAME_SIZE * 1, FRAME_SIZE, FRAME_SIZE};
    sfSprite_setTextureRect(combat_gui->frame_sprite, combat_gui->frame_rect);
    sfSprite_setTexture(combat_gui->frame_sprite, combat_gui->frame_texture, sfFalse);
    sfSprite_setOrigin(combat_gui->frame_sprite, (sfVector2f){FRAME_SIZE / 2, FRAME_SIZE / 2});
    sfSprite_setPosition(combat_gui->frame_sprite, (sfVector2f){WIND_H / 2 + 800, WIND_W / 2});
    sfSprite_setScale(combat_gui->frame_sprite, (sfVector2f){2.5, 4});
    return combat_gui;
}

static void set_combat_null(combat_t *combat)
{
    if (!combat)
        return;
    combat->background = NULL;
    combat->combat_gui = NULL;
    combat->enemies = NULL;
    combat->player = NULL;
}

static combat_t *create_combat(void)
{
    combat_t *combat = malloc(sizeof(combat_t));
    if (!combat)
        return NULL;

    set_combat_null(combat);
    combat->background = sfSprite_create();
    if (!combat->background) {
        free(combat);
        return NULL;
    }

    combat->combat_gui = create_combat_gui();
    if (!combat->combat_gui) {
        free_combat(combat);
        return NULL;
    }

    sfSprite_setTexture(combat->background, get_texture(CBT_BACKGROUND), sfFalse);
    sfSprite_setPosition(combat->background, (sfVector2f){0, 0});

    combat->player = create_hero_combat(CBT_HERO_PATH, 100);
    if (!combat->player) {
        free_combat(combat);
        return NULL;
    }

    sfSprite_setOrigin(combat->player->sprite, (sfVector2f){UNIT_SIZE / 2, UNIT_SIZE / 2});
    sfSprite_setPosition(combat->player->sprite, (sfVector2f){WIND_H / 2 + 500, WIND_W / 2});
    return combat;
}

static void set_rpg_null(rpg_t *rpg)
{
    if (!rpg)
        return;
    rpg->clock = NULL;
    rpg->combat = NULL;
    rpg->keybinds = NULL;
    rpg->player = NULL;
    rpg->window = NULL;
}

rpg_t *init_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    if (!rpg)
        return NULL;

    set_rpg_null(rpg);

    rpg->window = create_window();
    if (!rpg->window) {
        free(rpg);
        return NULL;
    }

    rpg->player = create_unit(HERO_PATH, 100);
    if (!rpg->player) {
        printf("Échec création joueur !\n");
        free_rpg(rpg);
        return NULL;
    }

    rpg->keybinds = create_keybinds();
    if (!rpg->keybinds) {
        free_rpg(rpg);
        return NULL;
    }

    rpg->clock = sfClock_create();
    if (!rpg->clock) {
        free_rpg(rpg);
        return NULL;
    }

    rpg->combat = create_combat();
    if (!rpg->combat) {
        free_rpg(rpg);
        return NULL;
    }

    rpg->is_combat = false;
    return rpg;
}
