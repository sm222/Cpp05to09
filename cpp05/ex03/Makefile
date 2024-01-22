#name
NAME = ex02

CC = c++ -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		Intern.cpp\

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
