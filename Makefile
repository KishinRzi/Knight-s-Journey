##
## Knight's Journey Makefile — Clean & macOS-ready
##

SRC = \
	src/main.c \
	src/rpg_loop.c \
	src/texture_handeling.c \
	src/init_functions/init_rpg.c \
	src/combat/start_combat.c \
	src/combat/combat_loop.c \
	src/movements/unit_movements.c \
	src/animation_fonctions/player_movement_animation.c \
	src/event_functions/event_loop.c \
	src/event_functions/combat_event_loop.c \
	src/display_functions/display_window.c \
	src/display_functions/display_unit.c \
	src/display_functions/display_combat.c \
	src/free_functions/free.c

OBJ = $(SRC:.c=.o)

NAME = my_rpg

CC = gcc
# Ton include perso + Homebrew SFML
CFLAGS = -Wall -Wextra -Iinclude -I/opt/homebrew/include
# Libs Homebrew SFML/CSFML + chemin Homebrew lib
LDFLAGS = -L/opt/homebrew/lib -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
