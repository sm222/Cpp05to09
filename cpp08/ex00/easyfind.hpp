#pragma once

#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <iostream>

template <typename T>
typename T::iterator easyfind(T container, int i) {
  typename T::iterator it = std::find(container.begin(), container.end(), i);
  if (it == container.end())
    throw std::invalid_argument("i is not in container");
  return (it);
}


#endif // EASYFIND_HPP_
