#include "PmergeMe.hpp"
#include <chrono>

static double  getTimePassed(void) {
    static std::chrono::high_resolution_clock::time_point T;
    static bool init = false;
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
PmergeMe::PmergeMe(void) {
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other) {
  *this = other;
  return;
}

// Copy assignment overload
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  for (size_t i = 0; i < rhs._vec.size(); i++) {
    _vec.push_back(rhs._vec[i]);
  }
  for (size_t i = 0; i < rhs._deq.size(); i++) {
    _deq.push_back(rhs._deq[i]);
  }
  return *this;
}

// Default destructor
PmergeMe::~PmergeMe(void) {
}

template <typename T>
void PmergeMe::print(T &list) {
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list[i] << ' ';
  }
  std::cout << std::endl;
}

void PmergeMe::startAlgo(typeContainer type) {
  double time1 = 0;
  double time2 = 0;
  if (type == e_vector)
    print(_vec);
  getTimePassed();
  sort(_vec, 0, _vec.size() - 1, _vec.size() / 2);
  time1 = getTimePassed();
  if (type == e_vector)
    print(_vec);
  if (type == e_deque)
    print(_deq);
  getTimePassed();
  sort(_deq, 0, _deq.size() - 1, 5);
  time2 = getTimePassed();
  if (type == e_deque)
    print(_deq);
  std::cout << "vector speed = " << time1 << std::endl;
  std::cout << "deque speed  = " << time2 << std::endl;
}

void  PmergeMe::addNumber(int nb) {
  _vec.push_back(nb);
  _deq.push_back(nb);
}

