
#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <vector>
#include <deque>
#include <iostream>

using std::vector;
using std::deque;

template <typename T>
void insertionSort(T &list , int left, int right) {
  for (int i = left; i < right; i++) {
    int tmp = list[i + 1];
    int j = i + 1;
    while (j > left && list[j - 1] > tmp) {
      list[j] = list[j - 1];
      j--;
    }
  list[j] = tmp;
  }
  T   tmp(list.begin() + left, list.begin() + right + 1);
  for (size_t i = 0; i < tmp.size(); i++) {
    std::cout << tmp[i] << ' ';
  }
  std::cout << std::endl;
}

template <typename T>
void merge(T &list, int left, int midle, int right) {
  int n1 = midle - left + 1;
  int n2 = right - midle;
  T   LA(list.begin() + left, list.begin() + midle + 1);
  T   RA(list.begin() + midle + 1, list.begin() + right + 1);
  int RIDX = 0;
  int LIDX = 0;
  for (int i = left; i <= right; i++) {
    if (RIDX == n2) {
      list[i] = LA[LIDX];
      LIDX++;
    }
    else if (LIDX == n1) {
      list[i] = RA[RIDX];
      RIDX++;
    }
    else if (RA[RIDX] > LA[LIDX]) {
      list[i] = LA[LIDX];
      LIDX++;
    }
    else {
      list[i] = RA[RIDX];
      RIDX++;
    }
  }
}

template <typename T>
void  sort(T &list, int left, int right, int K) {
  if (right - left > K) {
    int middle = (left + right) / 2;
    sort(list, left, middle, K);
    sort(list, middle + 1, right, K);
    merge(list, left, middle, right);
  }
  else {
    insertionSort(list, left, right);
  }
}

// Class declaration

class PmergeMe {
  public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();
    void startAlgo(void);
    void addNumber(int nb);
  private:
    template <typename T>
    void print(T &list);
    vector<int> _vec;
    deque<int>  _deq;
};

#endif // PMERGEME_HPP_
