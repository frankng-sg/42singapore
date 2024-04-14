NAME:=philo
SRC:=error fork main philo_routine doctor_routine simulation time util
OBJS:=${SRC:=.o}
CC:=cc
CFLAGS:=-g -Wall -Wextra -Werror
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re $(NAME)

all: $(NAME)
$(NAME): ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I philo.h

${OBJS}:

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	$(RM) $(OBJS) $(LIB)
fclean: clean
	$(RM) $(NAME)
re: fclean all
