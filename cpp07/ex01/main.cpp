#include "iter.hpp"

void  print(char &c) {
  std::cout << c << std::endl;
}

void  ft_bzero(int &i) {
  i = 0;
}

int main(void) {
  char  test[] = "this is a test";
  int   array[] = {42, 56 , 60};

  iter(test, 15, &print);
  iter(array, 3, &ft_bzero);
  std::cout << array[0] << std::endl;
  std::cout << array[1] << std::endl;
  std::cout << array[2] << std::endl;
}