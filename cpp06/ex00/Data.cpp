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

bool  Data::getPrint(void) const {
  return(this->_print);
}


void  Data::setPrint(bool flag) {
  this->_print = flag;
}

// -------------------------------------


static int find_dot(std::string str) {
  for (size_t i = 0; i < str.length(); i++)
  {
    if (str[i] == '.')
      return (1);
  }
  return (0);
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
  setPrint(true);
}


Data::Data(std::string other) {
  for (size_t i = 0; i < 4; i++) {
    setErr(fit, i);
  }
  setPrint(false);
  if (other.back() == 'f' && find_dot(other))
  {
    try {
      _f = std::stof(other);
      valueToChar(this, _f);
      valueToInt(this, _f);
      valueToDouble(this, _f);
      setPrint(true);
    }
    catch(const std::exception& e)
    {
      std::cout << "float out of range" << std::endl;
      return ;
    }
  }
  else if (find_dot(other)) {
    try {
      _d = std::stod(other);
      valueToChar(this, _d);
      valueToInt(this, _d);
      valueTofloat(this, _d);
      setPrint(true);
      return ;
    }
    catch(const std::exception& e) {
      std::cout << "double out of range " << std::endl;
    }
    
  }
  else {
    try {
      _i = std::stoi(other);
      valueToChar(this, _i);
      valueTofloat(this, _i);
      valueToDouble(this, _i);
      setPrint(true);
    }
    catch(const std::exception& e) {
      std::cout << "int out of range" << std::endl;
    }
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

void  Data::printValue(void) {
  if (!getPrint())
    return ;
  //char                                                      //
  if (_err[e_char] == fit)
    std::cout << "char  : " << "'" << _c << "'" << std::endl;
  else if (_err[e_char] == noPrintable)
    std::cout << "char  : not printable" << std::endl;
  else if (_err[e_char] == impossible || _err[e_char] == tooBig)
    std::cout << "char  : outrange" << std::endl;
  //int                                                       //
  if (_err[e_int] == fit)
    std::cout << "int   : " << _i << std::endl;
  else if (_err[e_int] == tooBig || _err[e_int] == impossible)
    std::cout << "int   : outrange" << std::endl;
  // float                                                    //
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout.precision(1);
    if (_err[e_float] == fit)
    std::cout << "float : " << _f << 'f' << std::endl;
  else if (_err[e_float] == impossible || _err[e_float] == tooBig)
    std::cout << "float : outrange" << std::endl;
  // double                                                   //
  std::cout.precision(2);
  if (_err[e_double] == fit)
    std::cout << "double: " << _d << std::endl;
  else if (_err[e_double] == tooBig)
    std::cout << "double: impossible" << std::endl;
    //|                                                        //
}
