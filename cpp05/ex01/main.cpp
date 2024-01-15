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
    
  {
  }
  return(42);
}
