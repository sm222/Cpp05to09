
#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
  if (DEV)
    std::cout << GIT << "[*]" << RESET << "Bureaucrat Default constructor" << std::endl;
  if (grade > 150)
    throw GradeTooLowException();
  if (grade < 1)
    throw GradeTooHighException();
  _grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) {
  if (DEV)
    std::cout << YEL << "[*]" << RESET << "Bureaucrat Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (DEV)
    std::cout << ORG << "[*]" << RESET << "Bureaucrat Copy assignment overload" << std::endl;
  _name = rhs.getName();
  _grade = rhs.getGrade();
  return (*this);
}

// Default destructor
Bureaucrat::~Bureaucrat(void) {
  if (DEV)
    std::cout << RED << "[*]" << RESET << "Bureaucrat Default destructor" << std::endl;
}

short Bureaucrat::getGrade(void) const {
  return (_grade);
}

std::string Bureaucrat::getName(void) const {
  return (_name);
}

// grade
void  Bureaucrat::setGrade(int grade) {
  if (grade > 150)
    throw GradeTooLowException();
  if (grade < 1)
    throw GradeTooHighException();
  _grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("this grade is too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("this grade is too Low");
}

// print

std::ostream& operator<<(std::ostream& os, const Bureaucrat &ptr) {
  os << ptr.getName() << ", bureaucrat grade " << ptr.getGrade();
  return (os);
}