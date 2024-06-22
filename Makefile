#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = so_long


SRCS_SL = main.c so_long.c general_checker_maps.c checker_maps.c check_file.c utils.c \
		fill_map.c window_handling.c
OBJS_SL = $(SRCS_SL:.c=.o)

SRC_DIR	= ./sources
INC_DIR	= ./
CC = gcc
MF = Makefile

NAME = so_long
LIBFT_PATH = ./libft/libft.a
SL_HEADER_FILE = $(INC_DIR)/so_long.h
CFLAGS = -Wall -Wextra -Werror -fPIE

GFLAGS = -lXext -lX11 -lm -lz -pie
GPATH = ./mlx
MLX_PATH = $(GPATH)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(MF) $(LIBFT_PATH) $(MLX_PATH) $(OBJS_SL)
	$(CC) $(CFLAGS) $(OBJS_SL) $(LIBFT_PATH) $(MLX_PATH) $(GFLAGS) -o $(NAME)
	@echo  ""
	@printf "\033[1;32m%s\033[0m\n" "[so_long] Compiled successfully."

%.o: %.c $(SL_HEADER_FILE) $(MF)
	@printf "\033[1;32m|\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT_PATH): .libft

.libft:
	@make -s -C ./libft DEBUG=$(DEBUG)

$(MLX_PATH): .mlx

.mlx:
	@make -s -C $(GPATH)

clean:
	@make -s clean -C ./libft
	@make -s clean -C $(GPATH)
	@rm -f $(OBJS_SL)
	@printf "\033[1;31m%s\033[0m\n" "[so_long] Object files cleaned."

fclean: clean
	@make -s fclean -C ./libft
	@make -s clean -C $(GPATH)
	@rm -f $(NAME)
	@printf "\033[1;31m%s\033[0m\n" "[so_long] Cleaned successfully."

re: fclean all

.PHONY: all clean fclean re