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
  //*  "robotomy request";
  //*  "presidentialPardon request";
  //*  "shrubberyCreation request";
  {
    std::cout << std::endl << std::endl;
    std::cout << CYN << "[*]" << RESET << "test 1 <- base test" << std::endl;
    AForm *test = NULL;
    try
    {
      Intern bob;
      test = bob.makeForm("robotomy request", "Bender");
      std::cout << std::endl << *test << std::endl;
      Bureaucrat oli("oli", 50);
      std::cout << std::endl;
      oli.singForm(*test);
      oli.executeForm(*test);
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    delete test;
    std::cout << std::endl;
  }
  {
    std::cout << std::endl << std::endl;
    std::cout << CYN << "[*]" << RESET << "test 2 <-" << std::endl;
    AForm *test = NULL;
    try
    {
      Intern bob;
      test = bob.makeForm("presidentialPardon request", "Bender");
      std::cout << std::endl << *test << std::endl;
      Bureaucrat oli("oli", 50);
      std::cout << std::endl;
      oli.singForm(*test);
      oli.executeForm(*test);
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    delete test;
    std::cout << std::endl;
  }
  {
    std::cout << std::endl << std::endl;
    std::cout << CYN << "[*]" << RESET << "test 3 <-" << std::endl;
    AForm *test = NULL;
    try
    {
      Intern bob;
      test = bob.makeForm("presidentialPardon request", "mike");
      std::cout << std::endl << *test << std::endl;
      Bureaucrat oli("oli", 5);
      std::cout << std::endl;
      oli.singForm(*test);
      oli.executeForm(*test);
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    delete test;
    std::cout << std::endl;
  }
  {
    std::cout << std::endl << std::endl;
    std::cout << CYN << "[*]" << RESET << "test 4 <-" << std::endl;
    AForm *test = NULL;
    try
    {
      Intern bob;
      test = bob.makeForm("shrubberyCreation request", "presidential");
      std::cout << std::endl << *test << std::endl;
      Bureaucrat oli("oli", 5);
      std::cout << std::endl;
      oli.singForm(*test);
      oli.executeForm(*test);
      std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    delete test;
  }
  return(42);
}
