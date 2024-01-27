
#include "data.hpp"

int  main(void) {
  Data A;

  A.c = 'a';
  A.i = 42;
  uintptr_t ptr = serialize(&A);
  std::cout << ptr << std::endl;
  
  Data  *B = deserialize(ptr);
  std::cout << "c = " << B->c << " i = " << B->i << std::endl;
}