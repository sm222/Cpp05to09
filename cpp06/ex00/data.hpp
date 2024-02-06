
#ifndef DATA_HPP_
#define DATA_HPP_

# include <iostream>
# include <iomanip>
# include <cmath>
# include <limits>

template <typename T>
int  lookValueLimit(double value, T type) {
  (void)type;
  if (value > std::numeric_limits<T>::max() ||
      value < std::numeric_limits<T>::min())
        return(1);
  return (0);
}

enum  errType {
      fit,
      tooBig,
      impossible,
      noPrintable,
};

enum  valueType {
      e_char,
      e_int,
      e_float,
      e_double,
};

// Class declaration
class Data {
  public:
    Data(char c);
    //Data(int i);
    Data(std::string other);
    //Data(double d);
    Data(const Data &other);
    //char
    char getChar(void) const;
    void setChar(char c);
    //int
    int  getInt(void) const ;
    void setInt(int i);
    Data &operator=(const Data &rhs);
    ~Data();
    void  setErr(short err, int i);
    void  printValue(void);
  private:
    char    _c;
    int     _i;
    float   _f;
    double  _d;
    short   _err[4];
};

template <typename T>
int  valueToChar(Data *c, T type) {
  if (lookValueLimit(type, c->getChar()))
    c->setErr(tooBig, e_char);
  else if (!std::isprint(type))
    c->setErr(noPrintable, e_char);
  else
    c->setErr(fit, e_char);
  c->setChar(static_cast<char>(type));
  return (0);
}

template <typename T>
int  valueToInt(Data *c, T type) {
  if (lookValueLimit(type, c->getInt()))
    c->setErr(tooBig, e_int);
  else
    c->setErr(fit, e_int);
  c->setInt(static_cast<int>(type));
  return (0);
}

#endif // DATA_HPP_
