#include "Bureaucrat.hpp"
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
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET << "test 1 <- base test" << std::endl;
  {
    try
    {
      PresidentialPardonForm bob("bob");
      Bureaucrat             jon("jon", 44);

      std::cout << std::endl;
      std::cout << bob << std::endl;
      jon.singForm(bob);
      jon.executeForm(bob);
      //
      std::cout << std::endl;
      //
      for (size_t i = 0; i < 19; i++) {
        jon.increment();
      }
      jon.singForm(bob);
      jon.executeForm(bob);
      std::cout << std::endl;
      for (size_t i = 0; i < 20; i++) {
        jon.increment();
      }
      jon.singForm(bob);
      jon.executeForm(bob);
      std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET << "test 2 <- " << std::endl;
  {
    try
    {
      RobotomyRequestForm pascal("pascal");
      Bureaucrat          antoine("antoine", 1);
      //
      std::cout << std::endl << pascal << std::endl << std::endl;
      //
      antoine.singForm(pascal);
      std::cout << std::endl << pascal << std::endl << std::endl;
      for (size_t i = 0; i < 4; i++)
      {
        std::cout << std::endl;
        antoine.executeForm(pascal);
      }
      std::cout << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET << "test 3 <- " << std::endl;
  {
    try
    {
      ShrubberyCreationForm garden("garden");
      Bureaucrat            gorge("gorge", 55);
      //
      std::cout << std::endl << garden << std::endl << std::endl;
      gorge.singForm(garden);
      gorge.executeForm(garden);
      std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  return(42);
}
