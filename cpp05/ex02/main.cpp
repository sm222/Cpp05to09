#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main(void) {
  if (DEV)
  {
    std::cout << GIT << ">[*]" << RESET << " Default constructor" << std::endl;
    std::cout << YEL << ">[*]" << RESET << " Copy constructor" << std::endl;
    std::cout << ORG << ">[*]" << RESET << " Copy assignment overload" << std::endl;
    std::cout << RED << ">[*]" << RESET << " Default destructor" << std::endl;
  }
  // ********************************************************************* //
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET << "test 1 <- base test" << std::endl;
  
  Bureaucrat a("a", 1);

  RobotomyRequestForm pbergero("pbergero");
  a.singForm(pbergero);
  a.executeForm(pbergero);


  return(42);
}
