
#include "Intern.hpp"

static  AForm *makeRobot(std::string target) {
  return (new RobotomyRequestForm(target));
}

static  AForm *makePardon(std::string target) {
  return (new PresidentialPardonForm(target));
}

static  AForm *makeShrubbry(std::string target) {
  return (new ShrubberyCreationForm(target));
}



// Default constructor
Intern::Intern(void) {
  _ftList[0] = &makeRobot;
  _ftList[1] = &makePardon;
  _ftList[2] = &makeShrubbry;
  _name[0] = "robotomy request";
  _name[1] = "presidentialPardon request";
  _name[2] = "shrubberyCreation request";
  if (DEV4)
    std::cout << MAG << "[*]" << RESET << " void Intern" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &other) {
  if (DEV4)
    std::cout << YEL << "[*]" << RESET << " Intern Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
Intern &Intern::operator=(const Intern &rhs) {
  if (DEV4)
    std::cout << ORG << "[*]" << RESET << " Intern Copy assignment overload" << std::endl;
  (void)rhs;
  return *this;
}

// Default destructor
Intern::~Intern(void) {
  if (DEV4)
    std::cout << RED << "[*]" << RESET << " Intern Default destructor" << std::endl;
}

const char *Intern::NotRealForm::what(void) const throw() {
  return ("invalid Form");
}


AForm *Intern::makeForm(std::string type, std::string target) {
  for (size_t i = 0; i < 3; i++) {
    if (type == _name[i])
      return(_ftList[i](target));
  }
  throw NotRealForm();
}