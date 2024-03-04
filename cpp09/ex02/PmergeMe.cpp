#include "PmergeMe.hpp"
#include <chrono>

static double  getTimePassed(void) {
    static std::chrono::high_resolution_clock::time_point T;
    static bool init;
    if (!init) {
        T = std::chrono::high_resolution_clock::now();
        init = true;
        return 0;
    }
    init = false;
    std::chrono::duration<double, std::milli> ms = std::chrono::high_resolution_clock::now() - T;
    return ms.count();
}

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
  double time = 0;
  print(_vec);
  //std::cout << std::endl;
  getTimePassed();
  sort(_vec, 0, _vec.size() - 1, 2);
  time = getTimePassed();
  std::cout << "vector speed = " << time << std::endl;
  print(_vec);
  //std::cout << "- - - - - - - - - -  - - -" << std::endl;
  //print(_deq);
  //std::cout << std::endl;
 // getTimePassed();
  //sort(_deq, 0, _deq.size() - 1, 5);
  //time = getTimePassed();
  //std::cout << "deque speed  = " << time << std::endl;
  //print(_deq);
}

void  PmergeMe::addNumber(int nb) {
  _vec.push_back(nb);
  _deq.push_back(nb);
}

