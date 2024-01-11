
#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>
#include <stdexcept>

// Class declaration
class Bureaucrat {
 public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &rhs);
  ~Bureaucrat(void);

  short       getGrade(void) const;
  std::string getName(void) const;
  // Grade
  void  setGrade(int grade);
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
    const std::string _name;
    short             _grade;

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &ptr);

#endif // BUREAUCRAT_HPP_
