
#ifndef ARRAY_HPP_
# define ARRAY_HPP_

# include <iostream>
template <typename T>

class Array {
  public:
    Array(void);
    Array(const unsigned int n);
    Array(const Array<T> &other);
    ~Array(void);
    //|                           //
    Array<T>  &operator=(const Array<T> &rhs);
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
