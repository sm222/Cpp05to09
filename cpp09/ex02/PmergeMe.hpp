
#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <vector>
#include <deque>
#include <iostream>

using std::vector;
using std::deque;

template <typename T>
void insertionSort(T &list , int p, int q) {
  for (int i = p; i < q; i++) {
    int tmpval = list[i + 1];
    int j = i + 1;
    while (j > p && list[j - 1] > tmpval) {
      list[j] = list[j - 1];
      j--;
    }
  list[j] = tmpval;
  }
}

template <typename T>
void merge(T &list, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  T   LA(list.begin() + p, list.begin() + q + 1);
  T   RA(list.begin() + q + 1, list.begin() + r + 1);
  int RIDX = 0;
  int LIDX = 0;
  for (int i = 0; i <  r - p + 1; i++) {
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
void  sort(T &list, int p, int r, int K) {
  if (r - p  > K) {
    int q = (p + r) / 2;
    sort(list, p, q, K);
    sort(list, q + 1, r, K);
    merge(list, p, q, r);
  }
  else {
    insertionSort(list, p, r);
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
