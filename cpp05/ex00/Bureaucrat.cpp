
#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) {
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) {
  *this = other;
}

// Copy assignment overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
Bureaucrat::~Bureaucrat(void) {
}
