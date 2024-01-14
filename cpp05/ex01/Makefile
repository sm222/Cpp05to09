#name
NAME = ex00

CC = c++ -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp\
		Bureaucrat.cpp\
		Form.cpp\

OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
