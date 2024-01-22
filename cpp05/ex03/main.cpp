#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
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
  {
    try
    {
      Intern bob;
      AForm *test = bob.makeForm("robotomy equest", "Bender");
      delete test;
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    

  }
  return(42);
}
