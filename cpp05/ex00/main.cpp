#include "Bureaucrat.hpp"

int main(void) {
  {
    try
    {
      Bureaucrat paul("paul", 62);
      std::cout << paul << std::endl;
      paul.setGrade();
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
  return(42);
}
