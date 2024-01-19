
#ifndef AFORM_HPP_
#define AFORM_HPP_

class Bureaucrat;

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

# if (DEV == 1)
#  define DEV2 1
# else
#  define DEV2 0
# endif

// Class declaration
class AForm {
  public:
    AForm(std::string name, int toSing, int toRun);
    AForm(const AForm &other);
    AForm &operator=(const AForm &rhs);
    virtual ~AForm(void) = 0;
  
  class GradeTooHighException : public std::exception {
    public:
      const char *what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
    public:
      const char *what(void) const throw();
  };
    // get
    std::string getName(void) const;
    bool        isSign(void) const;
    short       gradeToRun(void) const;
    short       gradeToSign(void) const;
    //
    void        beSigned(Bureaucrat &ptr);
  
  private:
    void        sign(void);

    const std::string _name;
    bool              _sign;
    const short       _toSing;
    const short       _toRun;

};

std::ostream& operator<<(std::ostream &os, const AForm &ptr);

#endif // AFORM_HPP_
