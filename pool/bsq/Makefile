NAME    = bsq
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iincludes

SRCS    = srcs/main.c \
          srcs/map.c \
          srcs/parse.c \
          srcs/solve.c \
          srcs/utils.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
