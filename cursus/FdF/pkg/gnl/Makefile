# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:50:16 by vietnguy          #+#    #+#              #
#    Updated: 2023/12/24 13:48:07 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=cc
CFLAGS:=-std=c99 -Wall -Wextra -Werror
AR:= ar crs
RM:=rm -rf
SRCS:=src/gnl
OBJ:=$(SRCS:=.o)
TARGET:=gnl.a

.PHONY: all clean fclean re

GREEN:=\033[1;32m
RESET:=\033[0m

all: $(TARGET)
	@echo "$(GREEN)OK$(RESET)"

$(TARGET): $(OBJ)
	@$(AR) $(TARGET) $(OBJ)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"
clean: 
	@$(RM) $(OBJ)
	@echo "Clean *.o"
fclean: clean
	@$(RM) $(TARGET)
	@echo "Clean $(TARGET)"
re: fclean all
