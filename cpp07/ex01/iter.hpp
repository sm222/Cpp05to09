
#ifndef ITER_HPP_
# define ITER_HPP_

# include <iostream>

template <typename T, typename FT>
void  iter(T *ptr, size_t size, FT ft) {
  for (size_t i = 0; i < size; i++) {
    ft(ptr[i]);
  }
}

#endif // ITER_H
