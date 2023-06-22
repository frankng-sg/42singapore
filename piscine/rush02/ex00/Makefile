TARGET = rush-02
INCLUDE = ./include
SRC = main.c dict.c parse_dict.c stralloc.c strconv.c \
      strio.c strsplit.c strutil.c sortdict.c dictalloc.c \
      dictutil.c
PRE = ./src/
SRCS = ${addprefix ${PRE}, ${SRC}}
OBJS = ${SRCS:.c=.o}
CFLAGS = -g -Wall -Wextra -Werror -I ${INCLUDE}
CC = cc
RM = rm -f

.PHONY: all clean fclean re

all: ${TARGET}
${TARGET}: ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${TARGET}
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 
clean:
	$(RM) ${OBJS} 
fclean: clean
	$(RM) ${TARGET}
re: fclean all
