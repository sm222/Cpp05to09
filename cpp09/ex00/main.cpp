#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "need one file" << std::endl;
    return (2);
  }
  try {
    BitcoinExchange bitcoin(av[1]);

  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
    return (1);
  }
  return (0);
}