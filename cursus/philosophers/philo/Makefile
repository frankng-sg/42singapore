# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 19:51:00 by vietnguy          #+#    #+#              #
#    Updated: 2024/01/04 20:14:22 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET:=philo
SRC:=main error routine simulation time
OBJS:=${SRC:=.o}
CC:=cc
CFLAGS:=-g -std=c99 -Wall -Wextra -Werror
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

all: ${TARGET}
${TARGET}: ${OBJS} ${LIB}
	$(CC) $(CFLAGS) $(OBJS) -o ${TARGET}
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	$(RM) $(OBJS) 
fclean: clean
	$(RM) $(TARGET)
re: fclean all
