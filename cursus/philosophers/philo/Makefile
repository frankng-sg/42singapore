NAME:=philo
SRC:=time time_test util util_test
MAIN:=$(SRC) main
UTEST:=$(SRC) main_test
MAIN_OBJS:=${MAIN:=.o}
UTEST_OBJS:=${UTEST:=.o}
CC:=cc
CFLAGS:=-g -Wall -Wextra -Werror
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re test $(NAME)

all: $(NAME)
$(NAME): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $(NAME) -I philo.h

test: fclean $(UTEST_OBJS)
	$(CC) $(CFLAGS) $(UTEST_OBJS) -o $(NAME) -I philo.h
	./$(NAME)
	make fclean
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	$(RM) *.o
fclean: clean
	$(RM) $(NAME)
re: fclean all
