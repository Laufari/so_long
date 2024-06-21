#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = so_long

SOURCES = main.c so_long.c general_checker_maps.c checker_maps.c check_file.c safe_malloc.c \
		fill_map.c


OBJECTS = $(SOURCES:%.c=%.o)

CFLAGS = -g -Wall -Werror -Wextra -I./ #-fsanitize=address 
LDFLAGS = -L ./minilibx-linux -L ./libft
CC = cc
RM = rm -f

MLX_FLAGS = -L ./minilibx-linux -lXext -lX11 -o $(NAME)

LIBFT_FLAGS = -L ./libft -lft

subsistem:
	make -C ./libft all
	make -C ./minilibx-linux all

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: subsistem $(NAME)

$(MLX):
	@$(MAKE) -C ./minilibx-linux --no-print-directory

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(NAME): Makefile $(SOURCES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SOURCES) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)SO_LONG DONE$(END)"

clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C ./libft clean --no-print-directory
	@$(MAKE) -C ./minilibx-linux clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft clean --no-print-directory
	@$(MAKE) -C ./minilibx-linux clean --no-print-directory


re: fclean all

.PHONY: all clean fclean re
