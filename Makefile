## rpg/Makefile
SRC = src/main.c src/game.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system
NAME = rpg

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
