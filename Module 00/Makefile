CC=c++
CFLAGS=-Werror -Wextra -Werror -std=c++98

SRCS=megaphone.cpp
OBJS=megaphone.o

NAME=megaphone

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $@ -o $<

clean:
	rm -drf $(OBJS)

fclean: clean
	rm -drf $(NAME)

re: fclean all

.PHONY: all clean fclean re
