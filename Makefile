##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## it's a Makefile
##

SRC =	src/main.c\
		src/rpg_loop.c\
		src/texture_handeling.c\
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

OBJTEST =	$(SRCTEST:.c=.o)

OBJ = $(SRC:.c=.o)

NAME =	my_rpg

CFLAGS	=	-Wall\
					-Wextra\
					-I include/\
					-lcsfml-graphics\
					-lcsfml-system\
					-lcsfml-window\
					-lcsfml-audio\

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(OBJTEST)

fclean:	clean
	rm -f $(NAME) $(NAMETEST)

re:	fclean
	make all
