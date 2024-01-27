
#include "data.hpp"
#include <string>

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

void  cleanStr(std::string &str, size_t len) {
  while (str.length() > len && str.back() == '0') {
    str.pop_back();
  }
}

void cleanStrBack(std::string &str) {
  cleanStr(str, 3);
  if (str.front() == '0' && str.back() != '0')
  {
    std::cout << "yes" << std::endl;
  }
  else {
    std::cout << "no" << std::endl;
    str.erase(0, 1);
    str.erase(0, 1);
  }
}

void  printData(std::string std) {
  double value = std::atof(std.c_str());
  // char
  char c = static_cast<char>(value);
  std::cout << "char  : ";
  if (noneValue(value) || lookValueLimit(value, c))
    std::cout << "impossible";
  else if (!std::isprint(value))
    std::cout << "not printable";
  else
    std::cout << c;
  std::cout << std::endl;
  //
  int n = static_cast<int>(value);
  std::cout << "int   : ";
  if (noneValue(value) || lookValueLimit(value, n))
    std::cout << "impossible";
  else
    std::cout << n;
  std::cout << std::endl;
  //
  float f = static_cast<float>(value);
  double f3;
  double f2 = std::modf(value, &f3);
  std::string A = std::to_string(f3);
  std::string B = std::to_string(f2);
  std::cout << "A " << A << " B " << B << std::endl;
  cleanStr(A, 1);
  cleanStrBack(B);
  if (A.back() == '.' && B.front() == '0') {
    A.pop_back();
  }
  std::cout << "A " << A << " B " << B << std::endl;
  std::cout << "float : ";
  if (lookValueLimit(value, f) && value != 0) {
    std::cout << "impossible";
  }
  else if (value == 0)
    std::cout << "0.0";
  else
    std::cout << A << "." << B;
  if (!noneValue(f))
    std::cout << 'f';
  std::cout << std::endl;
  //
  std::cout << "double: " << value << std::endl;
}

int  main(int ac, char **av) {
  if (lookInput(ac, av))
    return (1);
  std::string input = av[1];
  if (limits(input))
    return (0);
  printData(input);
  return (0);
}
