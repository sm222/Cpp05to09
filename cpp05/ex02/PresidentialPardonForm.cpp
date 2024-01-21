#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {
  if (DEV3)
    std::cout << MAG << "[*]" << RESET << " void PresidentialPardonForm" << std::endl;
}

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("PresidentialPardonForm", 25, 5), _target(target) {
  if (DEV3)
    std::cout << GIT << "[*]" << RESET << " PresidentialPardonForm Default constructor" << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other.getTarget()) {
  if (DEV3)
    std::cout << YEL << "[*]" << RESET << " PresidentialPardonForm Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  (void)rhs;
  if (DEV3)
    std::cout << ORG << "[*]" << RESET << " PresidentialPardonForm Copy assignment overload" << std::endl;
  return *this;
}

// Default destructor
PresidentialPardonForm::~PresidentialPardonForm() {
  if (DEV3)
    std::cout << RED << "[*]" << RESET << " PresidentialPardonForm Default destructor" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const {
  return(this->_target);
}


void  PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  canRun(executor);
  std::cout << getTarget() << " a été pardonnée par Zaphod Beeblebrox" << std::endl;
}