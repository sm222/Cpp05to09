#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() {
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
  return;
}

// Copy assignment overload
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {
}

template <typename T>
void PmergeMe::print(T &list) {
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list[i] << ' ';
  }
  std::cout << std::endl;
}

void PmergeMe::startAlgo(void) {
  print(_vec);
  sort(_vec, 0, _vec.size() - 1, _vec.size() / 2);
  print(_vec);
  std::cout << "- - - - - - - - - -  - - -" << std::endl;
  print(_deq);
  sort(_deq, 0, _deq.size() - 1, _deq.size() / 2);
  print(_deq);
}

void  PmergeMe::addNumber(int nb) {
  _vec.push_back(nb);
  _deq.push_back(nb);
}

