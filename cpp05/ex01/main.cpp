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
    try
    {
      Form door("door", 5, 55);
      std::cout << door << std::endl;
      Form door2(door);
      std::cout << door2 << std::endl;
      Form door3 = Form("d3", 50, 50);
      std::cout << door3 << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }
    
  {
  }
  return(42);
}
