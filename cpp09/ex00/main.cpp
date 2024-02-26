#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "need one file" << std::endl;
    return (2);
  }
  try {
    BitcoinExchange bitcoin(av[1]);
    if (bitcoin.fileToMap()) {
      std::cout << 'A' << std::endl;
      bitcoin.printMap();
    }
    else
      std::cout << 'B' << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
    return (1);
  }
  return (0);
}