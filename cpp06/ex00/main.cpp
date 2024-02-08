
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

int isValid(std::string str) {
  std::string copy = str;
  int dot = 0;

  if (copy.back() == 'f')
    copy.pop_back();
  if (copy.front() == '-')
    copy.erase(0, 1);
  for (size_t i = 0; i < copy.length(); i++) {
    if (copy[i] == '.' && !std::isdigit(copy[i + 1]))
      return (-1);
    if (copy[i] == '.')
      dot++;
    else if (!std::isdigit(copy[i]))
      return (-1);
  }
  return (dot);
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
    int dot = isValid(input);
  
    if (dot > 1 || dot < 0)
    {
      if (dot > 1)
        std::cout << "to many dot" << std::endl;
      else
        std::cout << "invalid char" << std::endl;
      return (1);
    }
    Data  convert(input);
    convert.printValue();
  }
  return (0);
}
