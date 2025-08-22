FILES = instructions/push.c \
		instructions/reverse_rotate.c \
		instructions/rotate.c \
		instructions/swap.c \
		main.c \
		parsing.c \
		sort_five.c \
		sort_three.c \
		sort.c \
		utils.c

SRCS_DIR = src
OBJS_DIR = obj

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I./$(LIBFT_DIR)/inc -I./inc -g

NAME	= push_swap

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re fclean clean all
