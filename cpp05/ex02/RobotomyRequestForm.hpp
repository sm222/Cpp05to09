#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

# if (DEV == 1)
#  define DEV3 1
# else
#  define DEV3 0
# endif


// Class declaration
class RobotomyRequestForm : public AForm {
  private:
    RobotomyRequestForm(void);
  public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    ~RobotomyRequestForm(void);
    //
    std::string getTarget(void) const ;
    void execute(Bureaucrat const &executor) const;

  private:
    const std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP_
