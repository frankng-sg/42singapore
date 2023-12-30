# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:23:55 by vietnguy          #+#    #+#              #
#    Updated: 2023/12/30 20:56:30 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE:=./include
TARGET:=fractol
SRCDIR:=./src/
SRC:=main complex free init render_mandelbrot events events_handler
SRCS:=${addprefix ${SRCDIR}, ${SRC}}
OBJS:=${SRCS:=.o}
LIB:=libmlx.a libmlx_Linux.a libft.a gnl.a
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
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -L/usr/lib -Ipkg/mlx -lXext -lX11 -lm -lz -lbsd -o ${TARGET}
%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -o $@ -c $<
gnl.a:
	@make -C ./pkg/gnl
	@cp ./pkg/gnl/gnl.a .
libft.a:
	@make -C ./pkg/libft
	@cp ./pkg/libft/libft.a .
libmlx_Linux.a libmlx.a:
	@make -C ./pkg/mlx
	@cp ./pkg/mlx/libmlx_Linux.a .
	@cp ./pkg/mlx/libmlx.a .
clean:
	@$(RM) $(OBJS) $(LIB)
	@make fclean -C ./pkg/gnl
	@make fclean -C ./pkg/libft
	@make clean -C ./pkg/mlx
fclean: clean
	@$(RM) $(TARGET)
re: fclean all