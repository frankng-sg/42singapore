NAME:=philo
SRC:=time fork util philo simulation main
OBJS:=${SRC:=.o}
CC:=cc
CFLAGS:=-g -Wall -Wextra -Werror
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I philo.h
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	$(RM) *.o
fclean: clean
	$(RM) $(NAME)
re: fclean all
