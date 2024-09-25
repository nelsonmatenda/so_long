NAME			= libftprintf.a

INCLUDE 		= ./include
SRC				= ./src

CFLAGS			= -Wall -Wextra -Werror -g -I./include
FLAGLIB			= -rcs
RM				= /bin/rm -f

LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a

FT_PRINTF		= ft_printf_utils.c ft_putpointer.c ft_puthex.c ft_printf.c
OBJECTS			= $(FT_PRINTF:.c=.o)

all:				$(NAME)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cp $(LIBFT) $(NAME)
	@ar $(FLAGLIB) $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "-----SUCCESS TO CREATE FT_PRINTF!!!-----"

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

%.o: $(SRC)/%.c
	@echo -n .
	@cc $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJECTS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re: fclean all

checker:
	@norminette $(SRC)/ $(INCLUDE) $(LIBFT_DIR) | grep -v Norme -B1 || true

.PHONY: all re clean fclean
