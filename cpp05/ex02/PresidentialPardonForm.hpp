#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"
#include <iostream>
#include <fstream>

# if (DEV == 1)
#  define DEV3 1
# else
#  define DEV3 0
# endif


// Class declaration
class PresidentialPardonForm : public AForm {
  private:
    PresidentialPardonForm(void);
  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    ~PresidentialPardonForm(void);
    //
    std::string getTarget(void) const ;
    void execute(Bureaucrat const &executor) const;

  private:
    const std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_HPP_
