# include "MutantStack.hpp"
# include <iostream>


int main(void) {
  std::cout << std::endl << std::endl;
  {
    MutantStack<int> A;
    // add
    for (size_t i = 0; i < 3; i++) {
      A.push(i + 3);
    }
    //
    {
      MutantStack<int>::iterator it, itEnd;
      it = A.begin();
      itEnd =  A.end();
      while (it != itEnd) {
        std::cout << *it << std::endl;
        it++;
      }
    }
    std::cout << "- - -" << std::endl;
    {
      MutantStack<int>::reverse_iterator it, itRbegin;
      it = A.rend();
      for (itRbegin = A.rbegin(); it != itRbegin; itRbegin++) {
        std::cout << *itRbegin << std::endl;
      }
    }
  }
  std::cout << std::endl << std::endl;
  {
    MutantStack<int> B;
    //add
    for (size_t i = 0; i < 100; i++) {
      B.push(i);
    }
    MutantStack<int>::iterator it = B.begin();
    for (size_t i = 0; i < 50; i++) {
      it++;
    }
    std::cout << *it << std::endl;
    MutantStack<int> C(B);
    MutantStack<int>::iterator it2 = C.end();
    for (size_t i = 0; i < 40; i++) {
      it2--;
    }
    std::cout << *it2 << std::endl;
  }
  return (0);
}