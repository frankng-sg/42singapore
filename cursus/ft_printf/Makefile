SRCS := ft_puthex.c ft_putptr.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c 
OBJS := ${SRCS:.c=.o}
NAME := libftprintf.a
AR := ar rcs
CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
