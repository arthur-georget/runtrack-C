NAME = music
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c album.c
OBJ = $(SRC:.c=.o)
DEPS = album.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME) main.c

.PHONY: all clean fclean run