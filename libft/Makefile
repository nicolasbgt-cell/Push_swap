# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 08:47:46 by annlecre          #+#    #+#              #
#    Updated: 2026/06/24 07:02:07 by nbigot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
RM = rm -rf
VPATH = .:srcs/libft:srcs/printf:srcs/get_next_line

SRCS = \
	ft_strlen.c\
	ft_strdup.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_split.c\
	ft_isdigit.c\
	ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_itoa.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_lstsize.c\
	ft_calloc.c\
	ft_printf.c\
	mini_libft.c\
	printf_utilities1.c\
	printf_utilities2.c\
	get_next_line.c\
	get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
