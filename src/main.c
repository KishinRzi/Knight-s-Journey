#include "../include/my_rpg.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;

    srand(time(NULL));
    int menu_result = start_menu();
    if (menu_result == 0)
        return 0; // joueur a quitté depuis le menu
    if (!start_game())
        return 84;
    return 0;
}

bool start_game(void)
{
    rpg_t *rpg = init_rpg();

    if (!rpg)
        return false;

    rpg_loop(rpg);       // apl la vraie boucle de jeu
    free_rpg(rpg);      
    return true;
}

