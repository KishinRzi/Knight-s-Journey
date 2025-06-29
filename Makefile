SRC =	src/main.c\
		src/rpg_loop.c\
		src/texture_handling.c\
		src/init_functions/init_rpg.c\
		src/combat/start_combat.c\
		src/combat/combat_loop.c\
		src/movements/unit_movements.c\
		src/animation_fonctions/player_movement_animation.c\
		src/event_functions/event_loop.c\
		src/event_functions/combat_event_loop.c\
		src/display_functions/display_window.c\
		src/display_functions/display_unit.c\
		src/display_functions/display_combat.c\
		src/free_functions/free.c\
		src/menu/menu.c \


OBJ = $(SRC:.c=.o)

NAME = my_rpg

INCLUDES = -I/opt/homebrew/include -Iinclude
LDFLAGS = -L/opt/homebrew/lib -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS = -Wall -Wextra -Wno-deprecated-declarations -I/opt/homebrew/include -Iinclude
LDFLAGS = -L/opt/homebrew/lib -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
