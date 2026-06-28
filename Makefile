NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
       parse_args.c parsing_utils.c\
       stack_init.c stack_utils.c stack_free.c\
       operations_push.c operations_swap.c operations_rotate.c operations_reverse_rotate.c\
       sort_data.c sort_simple.c sort_medium.c sort_complex.c index.c bench.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re

