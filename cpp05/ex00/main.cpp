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
    std::cout << std::endl << std::endl;
    std::cout << CYN << "[*]" << RESET << "test 1 <- base test" << std::endl;
    try
    {
      Bureaucrat paul("paul", 62);
      std::cout << paul << std::endl;
      paul.increment();
      std::cout << paul << std::endl;
      Bureaucrat stef = paul;
      std::cout << stef << std::endl;
      stef.increment();
      stef.increment();
      stef.increment();
      std::cout << paul << std::endl;
      std::cout << stef << std::endl;
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET << "test 2 <-"  << std::endl;
  {
    //test with deap copy
    try
    {
      Bureaucrat paul("paul", 24);
      Bureaucrat cole(paul);
      for (size_t i = 0; i < 18; i++) {
        cole.decrement();
      }
      std::cout << paul << std::endl;
      std::cout << cole << std::endl;
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET <<  "test 3 <- grade too High" << std::endl;
  {
    try
    {
      Bureaucrat paul("paul", 0);
      paul.decrement();
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET <<  "test 4 <- grade too Low" << std::endl;
  {
    try
    {
      Bureaucrat paul("paul", 155);
      for (size_t i = 0; i < 5; i++) {
        paul.increment();
      }
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET <<  "test 5 <- using new" << std::endl;
  {
    Bureaucrat *paul = NULL;
    try
    {
      paul = new Bureaucrat("paul", 5);
      std::cout << *paul << std::endl;
    }
    catch(const std::exception& e) {
      delete paul;
      std::cout << e.what() << std::endl;
    }
      delete paul;
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << std::endl << std::endl;
  std::cout << CYN << "[*]" << RESET <<  "test 6 <- creat form " << std::endl;
  {
    try
    {
      Bureaucrat paul("paul", 10);
      std::cout << paul << std::endl;
      Bureaucrat mic = Bureaucrat("Mic", 1);
      std::cout << mic << std::endl;
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  return(42);
}
