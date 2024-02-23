#include "RPN.hpp"

static int  badArgs(int ac, char **av) {
  if (ac != 2 || *av[1] == 0) {
    std::cout << "bad args" << std::endl;
    return (1);
  }
  return (0);
}

int main(int ac, char **av) {
  if (badArgs(ac, av))
    return (2);
  try {
    RPN rpn(av[1]);
    rpn.calculate();
    rpn.printTop();
  }
  catch(const std::exception& e) {
    std::cout << "Error" << std::endl << e.what() << std::endl;
    return (1);
  }
  return (0);
}