
#name
NAME = RPN

CC = c++ -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp\
				RPN.cpp\


OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) "5 5 +  9 +"
	./$(NAME) "7 7 + 2 /"
	./$(NAME) "1 1 1 1 1 1 + + + + +"
