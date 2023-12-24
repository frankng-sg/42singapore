# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:23:55 by vietnguy          #+#    #+#              #
#    Updated: 2023/12/24 13:58:41 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE:=./include
TARGET:=fdf
SRCDIR:=./src/
SRC:=main
SRCS:=${addprefix ${SRCDIR}, ${SRC}}
OBJS:=${SRCS:=.o}
LIB:=libmlx_Linux.a libft.a gnl.a
CC:=cc
CFLAGS:=-g -std=c99 -Wall -Wextra -Werror -I ${INCLUDE}
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

GREEN:=\033[1;32m
RESET:=\033[0m

all: ${TARGET}
	@echo "$(GREEN)OK$(RESET)"
${TARGET}: ${OBJS} ${LIB}
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
gnl.a:
	@make -C ./pkg/gnl
	@cp ./pkg/gnl/gnl.a .
libft.a:
	@make -C ./pkg/libft
	@cp ./pkg/libft/libft.a .
libmlx_Linux.a:
	@cp ./pkg/minilibx/libmlx_Linux.a .
clean:
	@$(RM) $(OBJS) $(LIB)
	@make fclean -C ./pkg/gnl
	@make fclean -C ./pkg/libft
fclean: clean
	@$(RM) $(TARGET)
re: fclean all
