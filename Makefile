NAME = so_long
APP  = ./app/so_long.c
MLX  = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS = so_long.c
DIR_SRC = ./src/
DIR_OBJ = ./objs/
OBJS =	$(addprefix $(DIR_OBJ), $($(SRCS:.c=.o)))
FLAG =	-g -Wall -Wextra -Werror
# LIB MLX
MLX_DIR = ./mlx_linux
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_PATH = $(MLX_DIR)/libmlx.a
# LIB LIBFT
LIBFT =	./libft/libftprintf.a
LIB_DIR =	./libft

GREEN= \033[0;32m

all: $(NAME)

$(NAME):	$(DIR_OBJ) $(LIBFT) $(OBJS) mlx
	cc $(FLAG) $(APP) $(OBJS) $(MLX_PATH) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
	@echo "\n${GREEN}> so_long was successfuly compiled 🎉"

$(DIR_OBJ)%.o:	$(DIR_SRC)%.c
	cc $(FLAG) -c $< -o $@

$(LIBFT): $(LIB_DIR)
		@make -C $(LIB_DIR)

$(DIR_OBJ):
		@mkdir -p $(DIR_OBJ)
mlx:
	make -C $(MLX_DIR)

.PHONY: all clean fclean re mlx
