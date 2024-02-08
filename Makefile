NAME = so_long

LIBFT = libft/libft.a

MLX	= mlx/Makefile.gen

LIBMLX = -L ./mlx_linux -lmlx -lXext -lX11 -lm -lbsd

HEADER = include
FT_HEADER = ./libft/include

CC = gcc -g
CFLAGS = -I $(FT_HEADER) -I $(HEADER) -I ./mlx_linux -Wall -Werror -Wextra
OBJ_DIR = .object/

SRC = $(SRC_DIR)main.c $(SRC_DIR)map_validate.c $(SRC_DIR)map_init.c $(SRC_DIR)game_start.c $(SRC_DIR)ft_flood_fill.c $(SRC_DIR)free_utils.c $(SRC_DIR)draw_map.c \
		$(SRC_DIR)mlx_utils.c

SRC_DIR = src/

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -s -C mlx_linux
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)/so_long.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C mlx_linux/
	make clean -C libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
