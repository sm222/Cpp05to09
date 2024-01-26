

#ifndef DATA_HPP_
#define DATA_HPP_

# include <iostream>
# include <cmath>
# include <limits>

template <typename T>
int  lookValueLimit(long value, T type) {
  (void)type;
  if (value > std::numeric_limits<T>::max() ||
      value < std::numeric_limits<T>::min())
        return(1);
  return (0);
}

#endif // DATA_HPP_
