#include "../include/my_rpg.h"

static void free_texture_list(texture_t *texture_list)
{
    texture_t *tmp = NULL;

    if (!texture_list)
        return;
    while (texture_list) {
        tmp = texture_list;
        texture_list = texture_list->next;
        if (!tmp)
            continue;
        if (tmp->path)
            free(tmp->path);
        if (tmp->texture)
            sfTexture_destroy(tmp->texture);
        free(tmp);
    }
}

static texture_t *create_new_texture_node(char *str)
{
    texture_t *tmp = malloc(sizeof(texture_t));

    if (!tmp)
        return NULL;
    tmp->path = strdup(str);
    if (!tmp->path) {
        free(tmp);
        return NULL;
    }
    tmp->name = NULL;
    tmp->texture = sfTexture_createFromFile(str, NULL);
    if (!tmp->texture) {
        free(tmp->path);
        free(tmp);
        fprintf(stderr, "Cannot load texture %s.\n", str);
        return NULL;
    }
    return tmp;
}

sfTexture *get_texture(char *str)
{
    static texture_t *texture_list = NULL;
    texture_t *tmp = texture_list;

    if (!str) {
        free_texture_list(texture_list);
        return NULL;
    }
    for (; tmp; tmp = tmp->next) {
        if (!strcmp(tmp->path, str))
            return tmp->texture;
    }
    tmp = create_new_texture_node(str);
    if (!tmp) {
        free_texture_list(texture_list);
        exit(84);
    }
    tmp->next = texture_list;
    texture_list = tmp;
    return tmp->texture;
}
