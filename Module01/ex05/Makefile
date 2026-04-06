CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=main.cpp Harl.cpp
OBJS=$(SRCS:.cpp=.o)

NAME=Harl2.0

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
