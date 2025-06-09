NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs

SRC = ./ft_printf.c \
	./ft_printf_flags.c \
	./ft_printf_handlers_basic.c \
	./ft_printf_handlers_hex.c \
	./ft_printf_handlers_number.c \
	./ft_printf_utils.c \
	./ft_printf_utils_bonus.c \
	./ft_printf_utils_hex.c \
	./ft_printf_utils_number.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a ./$(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
