#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = so_long


SRCS_SL = src/main.c src/general_checker_maps.c \
        src/checker_maps.c src/check_file.c src/free_utils.c \
          src/utils_extra.c src/fill_map.c src/window_handling.c \
          src/press_key.c

OBJS_SL = $(SRCS_SL:.c=.o)

SRC_DIR	= ./src
INC_DIR	= ./#./inc
CC = gcc
MF = Makefile

NAME = so_long
LIBFT_PATH = ./libs/libft/libft.a
SL_HEADER_FILE = $(INC_DIR)/so_long.h
CFLAGS = -Wall -Wextra -Werror -fPIE -g -fsanitize=address -fsanitize=leak

GFLAGS = -lXext -lX11 -lm -lz -pie
GPATH = ./libs/mlx
MLX_PATH = $(GPATH)/libmlx_Linux.a

all: .libft .mlx $(NAME)

$(NAME): $(MF) $(LIBFT_PATH) $(MLX_PATH) $(OBJS_SL)
	$(CC) $(CFLAGS) $(OBJS_SL) $(LIBFT_PATH) $(MLX_PATH) $(GFLAGS) -o $(NAME)
	@echo  ""
	@printf "\033[1;32m%s\033[0m\n" "[so_long] Compiled successfully."

%.o: src/%.c $(SL_HEADER_FILE) $(MF)
	@printf "\033[1;32m|\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

.libft:
	@make -s -C ./libs/libft DEBUG=$(DEBUG)

.mlx:
	@make -s -C $(GPATH) all

clean:
	@make -s clean -C ./libs/libft
	@make -s clean -C $(GPATH)
	@rm -f $(OBJS_SL)
	@printf "\033[1;31m%s\033[0m\n" "[so_long] Object files cleaned."

fclean: clean
	@make -s fclean -C ./libs/libft
	@make -s clean -C $(GPATH)
	@rm -f $(NAME)
	@printf "\033[1;31m%s\033[0m\n" "[so_long] Cleaned successfully."

re: fclean all

.PHONY: all clean fclean re