
#name
NAME = PmergeMe

CC = c++ -Wall -Werror -Wextra -std=c++98 -O2

SRCS =	main.cpp\
				PmergeMe.cpp\



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
	./$(NAME) `jot -r 30 1 100000 | tr '\n' ' '`
	@echo '- - - - -  - - - - - - - - - - - - - - - '
	./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`