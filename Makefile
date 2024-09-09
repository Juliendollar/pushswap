NAME = push_swap
LIBFT_DIR = libft
PRINTF_DIR = printf
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_INC = $(LIBFT_DIR)  
PRINTF_INC = $(PRINTF_DIR) 

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I$(LIBFT_INC) -I$(PRINTF_INC)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf


SRC = push_swap.c instructions.c instructions2.c instructions3.c check_arg.c fill_tab.c tri.c tri2.c tri3.c tri4.c tri5.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

checker:
	@wget https://cdn.intra.42.fr/document/document/26932/checker_linux
	@chmod 777 checker_linux

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re

