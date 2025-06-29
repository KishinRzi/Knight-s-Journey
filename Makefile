## Makefile compatible macOS

SRC = src/main.c \
      src/game.c \
      src/player.c \
      src/enemy.c \
      src/hud.c

OBJ = $(SRC:.c=.o)
NAME = rpg

INCLUDE = -Iinclude -I/opt/homebrew/include
LIB = -L/opt/homebrew/lib
FLAGS = -Wall -Wextra
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIB) $(LDFLAGS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
