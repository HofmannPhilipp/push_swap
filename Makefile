CC = CC
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS_DIR = ./src
UTILS_DIR = ./utils
SRCS =	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/sort/sort.c $(SRCS_DIR)/sort/rotate_helpers.c \
		$(SRCS_DIR)/instructions/push.c $(SRCS_DIR)/instructions/swap.c \
		$(SRCS_DIR)/instructions/rotate.c $(SRCS_DIR)/instructions/reverse_rotate.c \
		$(SRCS_DIR)/list/init_list.c $(SRCS_DIR)/list/list_getters.c \
		$(SRCS_DIR)/list/list_operations.c $(SRCS_DIR)/list/print_list.c $(SRCS_DIR)/list/free_list.c \
		$(UTILS_DIR)/utils.c $(UTILS_DIR)/validation.c \



OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./utils/libft
LIBFT = $(LIBFT_DIR)/libft.a
GREEN = \033[32m
YELLOW = \033[33m
NC = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Compiled Successfully 😎$(NC)"

$(LIBFT):
	@echo "$(YELLOW)🚧Compiling🚧$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

debug:$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) -g

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re