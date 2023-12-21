# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:23:55 by vietnguy          #+#    #+#              #
#    Updated: 2023/12/21 16:59:25 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE:=./include
TARGET:=push_swap
SRCDIR:=./src/
SRC:=main stack stack2 stack3 stack4 sort utils util2
SRCS:=${addprefix ${SRCDIR}, ${SRC}}
OBJS:=${SRCS:=.o}
LIB:=libft.a
CC:=cc
CFLAGS:=-g -std=c99 -Wall -Wextra -Werror -I ${INCLUDE}
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

all: ${TARGET}
${TARGET}: ${OBJS} ${LIB}
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
libft.a:
	@make -C ./lib/libft
	@mv ./lib/libft/libft.a .
clean:
	@$(RM) $(OBJS) $(LIB)
fclean: clean
	@$(RM) $(TARGET)
re: fclean all
