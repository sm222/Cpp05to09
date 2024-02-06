
#include "Data.hpp"


int  lookInput(int ac, char **av) {
  if (ac > 2) {
    std::cout << "too much args" << std::endl;
    return (1);
  }
  else if (ac == 1) {
    std::cout << "need one argv" << std::endl;
    return (1);
  }
  else if (av[1] == 0 || av[1][0] == 0)
    return (1);
  return (0);
}

int  limits(std::string str) {
  if (str == "-inff" || str == "+inff" || str == "nanf" )
    str.pop_back();
  if (str == "-inf" || str == "+inf" || str == "nan") {
    std::cout << "char  : outrange" << std::endl;
    std::cout << "int   : outrange" << std::endl;
    std::cout << "float : " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
    return (1);
  }
  return (0);
}

int  noneValue(double value) {
  if (std::isnan(value) || std::isinf(value))
    return (1);
  return (0);
}


int  main(int ac, char **av) {
  char  c;

  if (lookInput(ac, av))
    return (1);
  std::string input = av[1];
  if (limits(input))
    return (0);
  if (input.length() == 1 && !std::isdigit(input.front()))
  {
    c = input.front();
    Data  convert(c);
    convert.printValue();
  }
  else {
    Data  convert(input);
    convert.printValue();
  }
  return (0);
}
