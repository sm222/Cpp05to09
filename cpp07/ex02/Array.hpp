
#ifndef ARRAY_HPP_
# define ARRAY_HPP_

# include <iostream>

template <typename T>

class Array {
  public:
    Array<T>(void);
    Array<T>(const unsigned int n);
    Array<T>(const Array<T> &other);
    ~Array<T>(void);
    //|                           //
    Array<T>  operator=(const Array<T> &rhs);
    T         &operator[](const unsigned int i) const;
    //|                           //
    unsigned int size() const;
    T           *getArray(void);
  private:
    T             *_array;
    unsigned int  _n;
};

#include "Array.tpp"

#endif // ARRAY_HPP_
