#include "Form.hpp"


// Default constructor
Form::Form(std::string name, int toSing, int toRun) 
: _name(name), _sing(false) {
  if (toRun > 150 || toSing > 150)
    throw GradeTooLowException();
  if (toRun < 1 || toSing < 1)
    throw GradeTooHighException();
  _toSing = toSing;
  _toRun = toRun;
}

// Copy constructor
Form::Form(const Form &other) {
  *this = other;
}

// Copy assignment overload
Form &Form::operator=(const Form &rhs) {
  return *this;
}

// Default destructor
Form::~Form() {

}

std::string Form::getName(void) {
  return (_name);
}

const char *Form::GradeTooHighException::what(void) const throw() {
  return ("Form grade too High");
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return ("Form grade too Low");
}