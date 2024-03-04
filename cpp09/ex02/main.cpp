#include "PmergeMe.hpp"


//https://iq.opengenus.org/merge-insertion-sort/

int main(int ac, char **av) {
  PmergeMe  algo;

  for (int i = 1; i < ac ; i++) {
    algo.addNumber(std::atoi(av[i]));
  }
  algo.startAlgo();
  
}
