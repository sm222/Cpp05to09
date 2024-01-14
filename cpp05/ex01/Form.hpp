
#ifndef FORM_HPP_
#define FORM_HPP_

#include <iostream>
#include <stdexcept>

// Class declaration
class Form {
  public:
    Form(std::string name, int toSing, int toRun);
    Form(const Form &other);
    Form &operator=(const Form &rhs);
    ~Form(void);
  
  class GradeTooHighException : public std::exception {
    public:
      const char *what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
    public:
      const char *what(void) const throw();
  };
  // get
  std::string getName(void);
  bool        isSing(void);
  


  private:
    std::string const _name;
    bool              _sing;
    short             _toRun;
    short             _toSing;

};

#endif // FORM_HPP_
