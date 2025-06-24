/*
** EPITECH PROJECT, 2023
** destroy all
** File description:
** function to destroy all memory allocated elements
*/

#include "../include/my_rpg.h"

static bool is_error(int ac, char **av, char **env)
{
    if (ac != 1 || !env || !av)
        return false;
    for (int i = 0; env[i]; i++) {
        if (!strncmp(env[i], "DISPLAY", 7)) {
            return true;
        }
    }
    fprintf(stderr, "not in a terminal.\n");
    return false;
}

int main(int ac, char **av, char **env)
{
    srand(time(NULL));
    if (!(is_error(ac, av, env)))
        return 84;
    if (!start_game())
        return 84;
    return 0;
}
