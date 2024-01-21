
#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <iostream>
#include <fstream>

# if (DEV == 1)
#  define DEV3 1
# else
#  define DEV3 0
# endif


// Class declaration
class ShrubberyCreationForm : public AForm {
  private:
    ShrubberyCreationForm(void);
  public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm(void);
    //
    std::string getTarget(void) const ;
    void execute(Bureaucrat const &executor) const;

  private:
    const std::string _target;
};

#endif // SHRUBBERYCREATIONFORM_HPP_
