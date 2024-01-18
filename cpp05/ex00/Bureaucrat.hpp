
#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

# ifndef COLORS
#  define COLORS
#  define RED	"\001\e[31m\002"
#  define GRN	"\001\e[32m\002"
#  define YEL	"\001\e[33m\002"
#  define BLU	"\001\e[34m\002"
#  define MAG	"\001\e[35m\002"
#  define CYN	"\001\e[36m\002"
#  define WHT	"\001\e[37m\002"
#  define ORG	"\001\e[38;5;202m\002"
#  define PIK	"\001\e[38;5;176m\002"
#  define TOX	"\001\e[38;5;51m\002"
#  define RESET	"\001\e[0m\022"
#  define CLE	"\001\e[1;1H\x1b[2J\002"
#  define GIT	"\001\e[38;5;82m\002"
#  define GIT_B	"\001\e[38;5;94m\002"
# endif

#include <iostream>
#include <stdexcept>

# define DEV 1

// Class declaration
class Bureaucrat {
  public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat(void);
    //
    short       getGrade(void) const;
    std::string getName(void) const;
    void        increment(void);
    void        decrement(void);
    // Grade
    class GradeTooHighException : public std::exception {
      public:
        const char *what(void) const throw();
    };
    //
    class GradeTooLowException : public std::exception {
      public:
        const char *what(void) const throw();
    };

  private:
    void        setGrade(int grade);
    std::string const _name;
    short             _grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ptr);

#endif // BUREAUCRAT_HPP_
