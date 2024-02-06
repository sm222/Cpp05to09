#include "Data.hpp"

// Get and Set
char  Data::getChar(void) const {
  return (this->_c);
}

void  Data::setChar(char c) {
  this->_c = c;
}

int Data::getInt(void) const {
  return (this->_i);
}

void Data::setInt(int i) {
  this->_i = i;
}

float Data::getFloat(void) const {
  return (this->_f);
}

void  Data::setFloat(float f) {
  this->_f = f;
}

double  Data::getDouble(void) const {
  return (this->_d);
}

void  Data::setDouble(double d) {
  this->_d = d;
}

// -------------------------------------

Data::Data(char c) {
  for (size_t i = 0; i < 4; i++) {
    setErr(fit, i);
  }
  _c = c;
  if (!std::isprint(_c))
    setErr(noPrintable, e_char);
  _i = static_cast<int>(c);
  _f = static_cast<float>(c);
  _d = static_cast<double>(c);
}

/*
int isValid(std::string str) {

}
*/

Data::Data(std::string other) {
  for (size_t i = 0; i < 4; i++) {
    setErr(fit, i);
  }
  if (other.back() == 'f')
  {
    std::cout << "moi " << other.c_str() << std::endl;
    try
    {
      _f = std::stof(other);
      valueToChar(this, _f);
      valueToInt(this, _f);
      valueToDouble(this, _f);
    }
    catch(const std::exception& e)
    {
      for (size_t i = 0; i < 4; i++) {
        setErr(tooBig, i);
      }
      return ;
    }
  }
  else if (other.length() < 11 || (other.length() < 12 && other.front() == '-')) {
    try
    {
      _i = std::stoi(other);
      valueToChar(this, _i);
      valueTofloat(this, _i);
      valueToDouble(this, _i);
      return ;
    }
    catch(const std::exception& e)
    {
      std::cout << "bad\n";
    }
  }
  _d = std::stod(other);
  valueToChar(this, _d);
  valueToInt(this, _d);
  valueTofloat(this, _d);
}

Data::Data(const Data &other) {
  (void)other;
}

Data &Data::operator=(const Data &rhs) {
  (void)rhs;
  return (*this);
}

Data::~Data(void) {
}

void  Data::setErr(short err, int i) {
  _err[i] = err;
}

void  cleanStr(std::string &str, size_t len) {
  while (str.length() > len && str.back() == '0') {
    str.pop_back();
  }
}

void cleanStrBack(std::string &str) {
  cleanStr(str, 3);
  if (str.front() == '0' && str.back() != '0') {
  }
  else {
    str.erase(0, 2);
  }
}

std::string  editF(float f) {
  std::string value;
  value = std::to_string(f);
  double f3;
  double f2 = std::modf(f, &f3);
  std::string A = std::to_string(f3);
  std::string B = std::to_string(f2);
  cleanStr(A, 1);
  cleanStrBack(B);
  if (A.back() == '.')
    A.pop_back();
  if (std::strncmp(B.c_str(), "0.", 2) == 0)
    B.erase(0, 2);
  while (B.length() > 1)
    B.pop_back();
  std::string str = (A + "." + B);
  return (str);
}

std::string  editD(double d) {
  std::string value;
  value = std::to_string(d);
  double d3;
  double d2 = std::modf(d, &d3);
  std::string A = std::to_string(d3);
  std::string B = std::to_string(d2);
  cleanStr(A, 1);
  cleanStrBack(B);
  if (A.back() == '.')
    A.pop_back();
  if (std::strncmp(B.c_str(), "0.", 2) == 0)
    B.erase(0, 2);
  while (B.length() > 2)
    B.pop_back();
  std::string str = (A + "." + B);
  return (str);
}

void  Data::printValue(void) {
  //char
  std::cout << _err[e_char] << std::endl;
  if (_err[e_char] == fit)
    std::cout << "char  : " << "'" << _c << "'" << std::endl;
  else if (_err[e_char] == noPrintable)
    std::cout << "char  : not printable" << std::endl;
  else if (_err[e_char] == impossible || _err[e_char] == tooBig)
    std::cout << "char  : outrange" << std::endl;
  //int
  if (_err[e_int] == fit)
    std::cout << "int   : " << _i << std::endl;
  else if (_err[e_int] == tooBig)
    std::cout << "int   : impossible" << std::endl;
  else if (_err[e_int] == impossible)
    std::cout << "int   : outrange" << std::endl;
  // float
    if (_err[e_float] == fit)
    std::cout << "float : " << _f << 'f' << std::endl;
  else if (_err[e_float] == tooBig)
    std::cout << "float : outrange" << std::endl;
  else if (_err[e_float] == impossible)
    std::cout << "float : impossible" << std::endl;
  // double
  if (_err[e_double] == fit)
    std::cout << "double: " << _d << std::endl;
  else if (_err[e_double] == tooBig)
    std::cout << "double: impossible" << std::endl;
  else if (_err[e_double] == impossible)
    std::cout << "double: impossible" << std::endl;
}
