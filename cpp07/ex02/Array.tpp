
template <typename T>
Array<T>::Array(void): _array(nullptr), _n(0) {
}

template <typename T>
Array<T>::Array(const unsigned int n): _array(new T[n]), _n(n) {
}

template <typename T>
Array<T>::Array(const Array<T> &other) {
  *this = other;
}

template <typename T>
Array<T>::~Array(void) {
  if (_array)
    delete[] _array;
}

template <typename T>
Array<T>  &Array<T>::operator=(const Array<T> &rhs) {
  if (this == &rhs)
    return (*this);
  if (_array)
    delete[] _array;
  _array = new T[rhs._n];
  _n = rhs._n;
  for (unsigned int i = 0; i < rhs._n; i++) {
    _array[i] = rhs._array[i];
  }
  return (*this);
}

template <typename T>
T         &Array<T>::operator[](const unsigned int i) const {
  if (i > this->_n)
    throw std::out_of_range("i out of range");
  return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) const {
  return (this->_n);
}

template <typename T>
T         *Array<T>::getArray(void) {
  return (this->_array);
}