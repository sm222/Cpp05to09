#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
  string  tmp;
  if (ac != 2) {
    std::cout << "need one file" << std::endl;
    return (2);
  }
  try {
    BitcoinExchange bitcoin(av[1]);
    if (bitcoin.fileToMap()) {
      //bitcoin.printMap();
      bitcoin.readInFile(tmp);
      if (tmp != "date | value")
        throw std::runtime_error("bad header");
      while (bitcoin.readInFile(tmp)) {
        bitcoin.findValue(tmp);
      }
    }
    else
      std::cout << "error to inport data.csv" << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
    return (1);
  }
  return (0);
}