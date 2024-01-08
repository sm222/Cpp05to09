
#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <iostream>

// Class declaration
class Bureaucrat {
 public:
  Bureaucrat(void);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &rhs);
  ~Bureaucrat(void);

 private:
  std::string _name;
  short       _grade;

};

#endif // BUREAUCRAT_HPP_
