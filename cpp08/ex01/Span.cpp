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
    throw std::out_of_range("out of range");
  _vec.push_back(number);
}

int Span::longestSpan(void) const {
  if (_vec.size() < 2)
    throw std::out_of_range("need at least 2 number");
  std::vector<int> sorted = getVet();
  std::sort(sorted.begin(), sorted.end());
  return (std::abs(*(sorted.end() - 1) - *(sorted.begin())));
}


int Span::shortestSpan(void) const {
  if (_vec.size() < 2)
    throw std::out_of_range("need at least 2 number");
  int min = std::numeric_limits<int>::max();
  for (size_t i = 0; i < _vec.size() - 1; i++) {
    int tmp = std::abs(_vec[i] - _vec[i + 1]);
    if (tmp < min)
      min = tmp;
    if (tmp == 0)
      return (0);
  }
  return (min);
}

/*
using std::vector;
int Span::shortestSpan() const {

  vector<int> sorted = _vec;
  std::sort(sorted.begin(), sorted.end());

  int shortest_span = sorted[1] - sorted[0];
  for (vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1;
       ++it) {
    int span = *(it + 1) - *it;
    if (span < shortest_span) {
      shortest_span = span;
    }
  }
  return shortest_span;
}
*/
