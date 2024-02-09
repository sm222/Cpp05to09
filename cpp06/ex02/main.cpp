# include <iostream>
# include <cstdlib>
# include "ABC.hpp"

Base *generate(void) {
  Base  *p = NULL;
  srand((unsigned)std::time(NULL));
  int i = rand() % 3;
  if (i == 0) {
    std::cout << "make A" << std::endl;
    p = new A;
  }
  else if (i == 1) {
    std::cout << "make B" << std::endl;
    p = new B;
  }
  else if (i == 2) {
    std::cout << "make C" << std::endl;
    p = new C;
  }
  else
    std::cout << "make NULL" << std::endl;
  return (p);
}

void identify(Base *p) {
  if (dynamic_cast<A*>(p))
    std::cout << "pointer is A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "pointer is B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "pointer is C" << std::endl;
  else
    std::cout << "garbage 1" << std::endl;
}

void identify(Base &p) {
  try {
    A &aRef = dynamic_cast<A&>(p);
    std::cout << "reference is A" << std::endl;
    static_cast<void>(aRef);
    return ;
  }
  catch(const std::exception& e) {}
  try {
    B &bRef = dynamic_cast<B&>(p);
    static_cast<void>(bRef);
    std::cout << "reference is B" << std::endl;
    return ;
  }
  catch(const std::exception& e) {}
  try {
    C &cRef = dynamic_cast<C&>(p);
    static_cast<void>(cRef);
    std::cout << "reference is C" << std::endl;
    return ;
  }
  catch(const std::exception& e) {}
}



int main(void) {

  Base *p = generate();

  identify(p);
  identify(*p);

  delete p;
}