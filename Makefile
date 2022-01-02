NAME = so_long

SRCS = main.c \
		../getnl/get_next_line_utils.c \
		../getnl/get_next_line.c \
		player_move.c \
		map_components.c \
		error.c \
		free_map.c \
		check_file.c \
		hooks.c \
		window.c \
		ft_strchrr.c

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

MLX = -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx_linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX)
	@echo "\033[32m[ ./so_long created ]"

clean:
	$(RM) $(OBJS)
	make -C mlx_linux clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re