#include "Bureaucrat.hpp"
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
  ShrubberyCreationForm test("main");

  std::cout << test << std::endl;
  ShrubberyCreationForm test2(test);
  std::cout << test2 << std::endl;
  Bureaucrat a("a", 1);
  a.executeForm(test2);
  a.singForm(test2);
  std::cout << test2 << std::endl;

  return(42);
}
