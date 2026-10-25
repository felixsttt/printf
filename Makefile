NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

all: $(NAME)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re