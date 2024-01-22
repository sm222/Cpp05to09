#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {
  if (DEV3)
    std::cout << MAG << "[*]" << RESET << " void RobotomyRequestForm" << std::endl;
}

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("RobotomyRequestForm", 72, 45), _target(target) {
  if (DEV3)
    std::cout << GIT << "[*]" << RESET << " RobotomyRequestForm Default constructor" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other.getTarget()) {
  if (DEV3)
    std::cout << YEL << "[*]" << RESET << " RobotomyRequestForm Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  (void)rhs;
  if (DEV3)
    std::cout << ORG << "[*]" << RESET << " RobotomyRequestForm Copy assignment overload" << std::endl;
  return *this;
}

// Default destructor
RobotomyRequestForm::~RobotomyRequestForm() {
  if (DEV3)
    std::cout << RED << "[*]" << RESET << " RobotomyRequestForm Default destructor" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const {
  return(this->_target);
}


void  RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  canRun(executor);
  for (size_t i = 0; i < 3; i++)
  {
    std::cout << "Bre Bre Bre" << std::endl;
    usleep(5000 * 100);
  }
  std::srand(static_cast<unsigned int>(std::time(0)));
  if (std::rand() % 2 == 0)
    std::cout << getTarget() << " has been robotomized" << std::endl;
  else
    std::cout << getTarget() << " failed to be robotomize" << std::endl;
}