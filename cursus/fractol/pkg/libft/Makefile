# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 14:29:25 by vietnguy          #+#    #+#              #
#    Updated: 2023/12/31 00:44:21 by vietnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=cc
CFLAGS:=-g -std=c99 -Wall -Wextra -Werror
AR:=ar crs
RM:=rm -rf
FILES:=ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper \
	ft_tolower ft_atoi ft_strncmp ft_strlen ft_strnstr ft_strcmp \
	ft_strrchr ft_strchr ft_strlcat ft_strlcpy ft_memcmp ft_memchr \
	ft_memmove ft_memcpy ft_bzero ft_memset ft_calloc ft_strdup \
	ft_substr ft_strjoin ft_strtrim ft_strndup ft_min ft_max ft_split \
	ft_wordcount ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
	ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_putchar ft_atod \
	ft_puterr ft_putnbr ft_puthex ft_putptr ft_printf ft_putstr ft_replace
SRCS:=${FILES}
OBJ:=$(SRCS:=.o)
NAME:=libft.a

RED := \033[1;31m
GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m
RESET := \033[0m

.PHONY: all clean fclean re

all: $(NAME) 
	@echo "$(GREEN)OK$(RESET)"

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@$(RM) $(OBJ) $(BOBJ)
	@echo "$(YELLOW)Cleaned *.o$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Cleaned $(NAME)$(RESET)"

re: fclean all
