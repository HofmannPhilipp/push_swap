CC = CC
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS_DIR = ./src
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/instructions.c $(SRCS_DIR)/list.c ./utils/utils.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./utils/libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

debug:$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean



re: fclean all

.PHONY: all clean fclean re