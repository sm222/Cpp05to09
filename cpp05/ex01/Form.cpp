#include "Form.hpp"

Form::Form(void) : _name(""), _sign(false), _toSing(0), _toRun(0) {
  std::cout << MAG << "[*]" << RESET << " void Form" << std::endl;
}

// Default constructor
Form::Form(std::string name, int toSing, int toRun) : _name(name), _sign(false), _toSing(toSing), _toRun(toRun) {
  if (DEV2)
    std::cout << GIT << "[*]" << RESET << "Form Default constructor" << std::endl;
  if (toRun > 150 || toSing > 150)
    throw GradeTooLowException();
  if (toRun < 1 || toSing < 1)
    throw GradeTooHighException();
}

// Copy constructor
Form::Form(const Form &other) : _name(other.getName()), _sign(other.isSign()), _toSing(other.gradeToSign()),  _toRun(other.gradeToRun()) {
  if (DEV2)
    std::cout << YEL << "[*]" << RESET << "Form Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
Form &Form::operator=(const Form &rhs) {
  if (DEV2)
    std::cout << ORG << "[*]" << RESET << "Form Copy assignment overload" << std::endl;
  (void)rhs;
  return (*this);
}

// Default destructor
Form::~Form() {
  if (DEV2)
    std::cout << RED << "[*]" << RESET << "Form Default destructor" << std::endl;
}

std::string Form::getName(void) const {
  return (_name);
}

bool Form::isSign(void) const {
  return (_sign);
}

short Form::gradeToRun(void) const {
  return (_toRun);
}

short Form::gradeToSign(void) const {
  return (_toSing);
}

const char *Form::GradeTooHighException::what(void) const throw() {
  return ("Form grade too High");
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return ("Form grade too Low");
}

void  Form::sign(void) {
  _sign = true;
}

void  Form::beSigned(Bureaucrat &ptr) {
  if (ptr.getGrade() <= this->gradeToSign()) {
    this->sign();
  }
  else
    throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& os, const Form &ptr) {
  std::string  s;

  if (ptr.isSign())
    s = "[X] ";
  else
    s = "[ ] ";
  os << s << ptr.getName() << " : " << ptr.gradeToRun() << " need to run and " << ptr.gradeToSign() \
  << " to Sign it.";
  return (os);
}