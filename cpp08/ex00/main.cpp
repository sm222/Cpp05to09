# include "easyfind.hpp"
# include <vector>
# include <iostream>

int main(void) {
  std::vector<int>  list;
  for (size_t i = 1; i < 10; i++) {
    list.push_back(42 * i);
  }
  //test 1
  try {
    std::vector<int>::iterator it = easyfind(list, 42);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  //test 2
  try {
    std::vector<int>::iterator it = easyfind(list, 168);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  //test 3
  try {
    std::vector<int>::iterator it = easyfind(list, 160);
    std::cout << *it << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}