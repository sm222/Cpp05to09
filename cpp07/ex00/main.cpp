# include "whatever.hpp"
# include <iostream>

int main(void) {

  int  a = 10, b = 20;

  int   *ap, *bp;
  std::cout << "a = " << a << "; b = " << b << std::endl;
  std::cout << "max " << max(a, b) << std::endl;
  std::cout << "min " << min(a, b) << std::endl;
  ap = &a;
  bp = &b;
  std::cout << "a = " << ap << "; b = " << bp << std::endl;
  swap(ap, bp);
  std::cout << "a = " << ap << "; b = " << bp << std::endl;
}