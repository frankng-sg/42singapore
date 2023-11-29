# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:23:55 by vietnguy          #+#    #+#              #
#    Updated: 2023/11/29 13:16:45 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE:=./include
TARGET:=pipex
SRCDIR:=./src/
SRC:=main.c
SRCS:=${addprefix ${SRCDIR}, ${SRC}}
OBJS:=${SRCS:.c=.o}
LIB:=gnl.a libft.a
CC:=cc
CFLAGS:=-std=c99 -Wall -Wextra -Werror -I ${INCLUDE}
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

all: ${TARGET} clean
${TARGET}: ${OBJS} ${LIB}
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
gnl.a:
	@make -C ./lib/gnl
	@mv ./lib/gnl/gnl.a .
libft.a:
	@make -C ./lib/libft
	@mv ./lib/libft/libft.a .
clean:
	@$(RM) $(OBJS) $(LIB)
fclean: clean
	@$(RM) $(TARGET)
re: fclean all