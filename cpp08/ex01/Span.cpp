#include "Span.hpp"

// Default constructor
Span::Span(void) : _limit(0) {
}

Span::Span(unsigned int N) : _limit(N) {
}

// Copy constructor
Span::Span(const Span &other) {
  *this = other;
  return;
}

// Copy assignment overload
Span &Span::operator=(const Span &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
Span::~Span(void) {
}

void  Span::addNumber(int number) {
  if (_vec.size() >= _limit)
    throw std::
}