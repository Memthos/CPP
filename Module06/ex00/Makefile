CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g

SRCS=main.cpp ScalarConverter.cpp
OBJS=$(SRCS:.cpp=.o)

NAME=ScalarConverter

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
