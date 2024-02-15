#include "Span.hpp"

// Default constructor
Span::Span(void) : _limit(0) {
}

Span::Span(unsigned int N) : _limit(N) {
}

// Copy constructor
Span::Span(const Span &other) {
  *this = other;
}

// Copy assignment overload
Span &Span::operator=(const Span &rhs) {
  this->_limit = rhs.getLimit();
  this->_vec = rhs.getVet();
  return *this;
}

// Default destructor
Span::~Span(void) {
}

int Span::getLimit(void) const {
  return (this->_limit);
}

std::vector<int> Span::getVet(void) const {
  return (this->_vec);
}


void  Span::addNumber(int number) {
  if (_vec.size() >= _limit)
    throw std::out_of_range("");
  _vec.push_back(number);
}

int Span::longestSpan(void) const {
  if (_vec.size() < 2)
    throw std::out_of_range("need at least 2 number");
  std::vector<int> sorted = getVet();
  std::sort(sorted.begin(), sorted.end());
  return (*(sorted.end() - 1) - *(sorted.begin()));
}

/*
int shortestSpan() {
}
*/

