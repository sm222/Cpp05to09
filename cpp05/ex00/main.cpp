#include "Bureaucrat.hpp"

int main(void) {
  {
    // base test
    std::cout << "test 1 <-" << std::endl; 
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
    }
    catch(const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  /*- - - - - - - - - - - - - - - - - - - - - - - - -*/
  std::cout << "test 2 <-" << std::endl; 
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
  return(42);
}
