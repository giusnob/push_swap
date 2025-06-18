# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 20:46:15 by ginobile          #+#    #+#              #
#    Updated: 2025/06/18 17:38:37 by ginobile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I. -Iinclude -Ift_printf/libft -Ift_printf
RM = rm -f

FT_DIR = ft_printf

SRC = \
	srcs/main.c \
	srcs/utils.c \
	srcs/operations.c \
	srcs/sort.c \
	srcs/small.c \
	srcs/parsing.c \
	srcs/radix.c

OBJS = $(SRC:.c=.o)

INCLUDES = -Iinclude -I$(FT_DIR)/libft -I$(FT_DIR)

all: $(FT_DIR)/libft/libft.a $(FT_DIR)/libftprintf.a $(NAME)

$(FT_DIR)/libft/libft.a:
	$(MAKE) -C $(FT_DIR)/libft

$(FT_DIR)/libftprintf.a:
	$(MAKE) -C $(FT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) \
		$(FT_DIR)/libft/libft.a $(FT_DIR)/libftprintf.a \
		-o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(FT_DIR)/libft clean
	@$(MAKE) -C $(FT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(FT_DIR)/libft/libft.a
	$(RM) $(FT_DIR)/libftprintf.a
	@$(MAKE) -C $(FT_DIR)/libft fclean
	@$(MAKE) -C $(FT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

