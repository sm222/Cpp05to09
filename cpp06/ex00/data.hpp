
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
    //Data(float f);
    //Data(double d);
    Data(const Data &other);
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

#endif // DATA_HPP_
