#include "AForm.hpp"

// Default constructor
AForm::AForm(std::string name, int toSing, int toRun) : _name(name), _sign(false), _toSing(toSing), _toRun(toRun) {
  if (DEV2)
    std::cout << GIT << "[*]" << RESET << "AForm Default constructor" << std::endl;
  if (toRun > 150 || toSing > 150)
    throw GradeTooLowException();
  if (toRun < 1 || toSing < 1)
    throw GradeTooHighException();
}

// Copy constructor
AForm::AForm(const AForm &other) : _name(other.getName()), _sign(other.isSign()), _toSing(other.gradeToSign()),  _toRun(other.gradeToRun()) {
  if (DEV2)
    std::cout << YEL << "[*]" << RESET << "AForm Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
AForm &AForm::operator=(const AForm &rhs) {
  if (DEV2)
    std::cout << ORG << "[*]" << RESET << "AForm Copy assignment overload" << std::endl;
  (void)rhs;
  return (*this);
}

// Default destructor
AForm::~AForm() {
  if (DEV2)
    std::cout << RED << "[*]" << RESET << "AForm Default destructor" << std::endl;
}

std::string AForm::getName(void) const {
  return (_name);
}

bool AForm::isSign(void) const {
  return (_sign);
}

short AForm::gradeToRun(void) const {
  return (_toRun);
}

short AForm::gradeToSign(void) const {
  return (_toSing);
}

const char *AForm::GradeTooHighException::what(void) const throw() {
  return ("Form grade too High");
}

const char *AForm::GradeTooLowException::what(void) const throw() {
  return ("Form grade too Low");
}

void  AForm::sign(void) {
  _sign = true;
}

void  AForm::beSigned(Bureaucrat &ptr) {
  if (ptr.getGrade() <= this->gradeToSign()) {
    this->sign();
  }
  else
    throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& os, const AForm &ptr) {
  std::string  s;

  if (ptr.isSign())
    s = "[X] ";
  else
    s = "[ ] ";
  os << s << ptr.getName() << " : " << ptr.gradeToRun() << " need to run and " << ptr.gradeToSign() \
  << " to Sign it.";
  return (os);
}