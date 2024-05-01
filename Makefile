CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = minishell

SRCS = minishell.c gc.c

LIBS = -lreadline

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%o: %c
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBS)

re:	fclean all

clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(BNAME)