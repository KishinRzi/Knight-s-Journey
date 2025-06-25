#include "../include/my_rpg.h"

static bool is_error(int ac)
{
    if (ac != 1)
        return false;
    return true;
}

int main(int ac, char **av, char **env)
{
    srand(time(NULL));
    if (!(is_error(ac)))
        return 84;
    if (!start_game())
        return 84;
    return 0;
}
