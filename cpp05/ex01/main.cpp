#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  if (DEV)
  {
    std::cout << GIT << ">[*]" << RESET << " Default constructor" << std::endl;
    std::cout << YEL << ">[*]" << RESET << " Copy constructor" << std::endl;
    std::cout << ORG << ">[*]" << RESET << " Copy assignment overload" << std::endl;
    std::cout << RED << ">[*]" << RESET << " Default destructor" << std::endl;
  }
  std::cout << CYN << "[*]" << RESET << "test 1 <- base test" << std::endl;
  {
    try
    {
      Form icecream("free ice cream", 99, 55);
      Bureaucrat paul("paul", 50);
      std::cout << paul << std::endl;

      std::cout << icecream << std::endl;
      paul.singForm(icecream);
      std::cout << icecream << std::endl;
      paul.singForm(icecream);
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    
  }
  return(42);
}
