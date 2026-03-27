CC=c++
CFLAGS=-Werror -Wextra -Werror -std=c++98

SRCS=tests.cpp Account.cpp
OBJS=$(SRCS:.cpp=.o)

NAME=log

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
