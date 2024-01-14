#include "Bureaucrat.hpp"

int main(void) {
  if (DEV)
  {
    std::cout << GIT << ">[*]" << RESET << " Default constructor" << std::endl;
    std::cout << YEL << ">[*]" << RESET << " Copy constructor" << std::endl;
    std::cout << ORG << ">[*]" << RESET << " Copy assignment overload" << std::endl;
    std::cout << RED << ">[*]" << RESET << " Default destructor" << std::endl;
  }
  {
    // base test
    std::cout << CYN << "[*]" << RESET << "test 1 <- base test" << std::endl;
    try
    {
      Bureaucrat paul("paul", 62);
      std::cout << paul << std::endl;
      paul.setGrade(69);
      std::cout << paul << std::endl;
      Bureaucrat stef = paul;
      std::cout << stef << std::endl;
      stef.setGrade(5);
      std::cout << paul << std::endl;
      std::cout << stef << std::endl;
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << CYN << "[*]" << RESET << "test 2 <-"  << std::endl;
  {
    //test with deap copy
    try
    {
      Bureaucrat paul("paul", 24);
      Bureaucrat cole(paul);
      cole.setGrade(42);
      std::cout << paul << std::endl;
      std::cout << cole << std::endl;
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << CYN << "[*]" << RESET <<  "test 3 <- grade too High" << std::endl;
  {
    // gread
    try
    {
      Bureaucrat paul("paul", 0);
      paul.setGrade(24);
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << CYN << "[*]" << RESET <<  "test 4 <- grade too Low" << std::endl;
  {
    // gread
    try
    {
      Bureaucrat paul("paul", 155);
      paul.setGrade(24);
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << CYN << "[*]" << RESET <<  "test 5 <- using new" << std::endl;
  {
    // gread
    Bureaucrat *paul = NULL;
    try
    {
      paul = new Bureaucrat("paul", 0);
      paul->setGrade(0);
    }
    catch(const std::exception& e) {
      delete paul;
      std::cout << e.what() << std::endl;
    }
      delete paul;
  }
  return(42);
}
