#pragma once

#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <vector>
#include <deque>

using std::vector;
using std::deque;

// Class declaration
class PmergeMe {
  public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();
  private:
    vector<int>  _vec;
    deque<int>   _deq;

};

#endif // PMERGEME_HPP_
