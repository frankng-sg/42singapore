# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 11:50:16 by vietnguy          #+#    #+#              #
#    Updated: 2023/11/29 13:14:06 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=cc
CFLAGS:=-std=c99 -Wall -Wextra -Werror
AR:= ar crs
RM:=rm -rf
SRCS:=get_next_line get_next_line_utils
OBJ:=$(SRCS:=.o)
TARGET:=gnl.a

.PHONY: all clean fclean re

all: $(TARGET) clean

$(TARGET): $(OBJ)
	@$(AR) $(TARGET) $(OBJ)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean: 
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(TARGET)
re: fclean all
