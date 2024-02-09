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
  else {
    std::cout << "make C" << std::endl;
    p = new C;
  }
  return (p);
}

void identify(Base *p) {
  if (dynamic_cast<A*>(p))
    std::cout << "pointer is A" << std::endl;
  if (dynamic_cast<B*>(p))
    std::cout << "pointer is B" << std::endl;
  if (dynamic_cast<C*>(p))
    std::cout << "pointer is C" << std::endl;
}

void identify(Base &p) {
  if (dynamic_cast<A*>(&p))
    std::cout << "reference is A" << std::endl;
  if (dynamic_cast<B*>(&p))
    std::cout << "reference is B" << std::endl;
  if (dynamic_cast<C*>(&p))
    std::cout << "reference is C" << std::endl;
}


int main(void) {

  Base *p = generate();

  identify(p);
  identify(*p);

  delete p;
}