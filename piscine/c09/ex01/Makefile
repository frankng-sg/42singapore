CC = cc
INCLUDES = ./includes/
TARGET = libft.a
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
PRE = ./srcs/
SRCS = ${addprefix ${PRE}, ${SRC}}
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror -I ${INCLUDES}

.PHONY: all clean fclean re

all: ${TARGET}
$(TARGET): ${OBJS}
	ar rcs ${TARGET} ${OBJS}
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${TARGET}
re: fclean all
