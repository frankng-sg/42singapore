TARGET:=philo
SRC:=error fork main routine simulation time util
OBJS:=${SRC:=.o}
CC:=cc
CFLAGS:=-g -std=c99 -Wall -Wextra -Werror
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

all: ${TARGET}
${TARGET}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o ${TARGET}

${OBJS}:

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	$(RM) $(OBJS) $(LIB)
fclean: clean
	$(RM) $(TARGET)
re: fclean all
