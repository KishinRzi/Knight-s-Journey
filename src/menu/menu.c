#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>

int start_menu(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    sfFont* font;
    sfText* text;

    window = sfRenderWindow_create(mode, "Menu Principal", sfResize | sfClose, NULL);
    if (!window)
        return 0;

    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font) {
        fprintf(stderr, "Erreur : police manquante (assets/fonts/arial.ttf).\n");
        sfRenderWindow_destroy(window);
        return 0;
    }

    text = sfText_create();
    sfText_setString(text, "Appuyez sur Entrée pour commencer\nÉchap pour quitter");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){100, 250});

    int code = -1;
    while (sfRenderWindow_isOpen(window) && code == -1) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                code = 0; // Fermer = quitter
            }
            if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeyEnter)
                    code = 1; // Commencer le jeu
                else if (event.key.code == sfKeyEscape)
                    code = 0;
            }
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }

    sfText_destroy(text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    return code;
}
