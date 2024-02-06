#include "Data.hpp"

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

Data::Data(std::string other) {
  for (size_t i = 0; i < 4; i++) {
    setErr(fit, i);
  }
  if (other.back() == 'f')
  {
    std::cout << "moi " << other.c_str() << std::endl;
    try
    {
      _f = std::stof(other.c_str());
    }
    catch(const std::exception& e)
    {
      for (size_t i = 0; i < 4; i++) {
        setErr(tooBig, i);
      }
      return ;
    }
    // char
    valueToChar(this, _f);
    valueToInt(this, _f);
  }
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
  std::string str = (A + "." + B);
  std::cout << str << std::endl;
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
    std::cout << "char  : impossible" << std::endl;
  //int
  if (_err[e_int] == fit)
    std::cout << "int   : " << _i << std::endl;
  else if (_err[e_int] == tooBig)
    std::cout << "int   : impossible" << std::endl;
  else if (_err[e_int] == impossible)
    std::cout << "int   : impossible" << std::endl;
  // float
    if (_err[e_float] == fit)
    std::cout << "float : " << editF(_f) << std::endl;
  else if (_err[e_float] == tooBig)
    std::cout << "float : impossible" << std::endl;
  else if (_err[e_float] == impossible)
    std::cout << "float : impossible" << std::endl;
}
