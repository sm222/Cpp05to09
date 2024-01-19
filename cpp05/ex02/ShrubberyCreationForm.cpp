#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int toSing, int toRun) :
AForm(name, toSing, toRun) {
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
_name(other.getName()){
  *this = other;
  return;
}

// Copy assignment overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() { 
}
