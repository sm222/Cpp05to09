#include "PmergeMe.hpp"


//https://iq.opengenus.org/merge-insertion-sort/
//./PmergeMe `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`

int parsing(int ac, char **av) {
  for (int i = 1; i < ac; i++) {
  size_t  len = std::strlen(av[i]);
    if (len > 10 || av[i][0] == '\0')
      return (1);
    for (size_t j = 0; j < len; j++) {
      if (std::strchr("0123456789", av[i][j]))
        continue ;
      else
        return (1);
    }
  }
  return (0);
}

int main(int ac, char **av) {
  if (parsing(ac, av)) {
    std::cout << "invalid number" << std::endl;
    return (1);
  }
  PmergeMe  algo;
  for (int i = 1; i < ac ; i++) {
    algo.addNumber(std::atoi(av[i]));
  }
  algo.startAlgo(e_vector);
  //PmergeMe a(algo);
  //a.startAlgo(e_deque);
  return (0);
}
