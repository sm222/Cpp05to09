
#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_


template <typename T>
void  swap(T &v1, T &v2) {
  T tmp;
  tmp = v2;
  v2 = v1;
  v1 = tmp;
}

template <typename T>
T min(const T &v1, const T &v2) {
  if (v2 <= v1)
    return (v2);
  return (v1);
}

template <typename T>
T max(const T &v1, const T &v2) {
  if (v2 >= v1)
    return (v2);
  return (v1);
}


#endif // WHATEVER_HPP_