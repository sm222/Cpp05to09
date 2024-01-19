
#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"
#include <iostream>

// Class declaration
class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(std::string name, int toSign, int toRun);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();

  private:
    
};

#endif // SHRUBBERYCREATIONFORM_HPP_
