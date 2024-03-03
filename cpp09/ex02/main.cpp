#include "PmergeMe.hpp"

//https://iq.opengenus.org/merge-insertion-sort/

const int K = 2;


void merge(vector<int> &list, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  vector<int>  LA(list.begin() + p, list.begin() + q + 1);
  vector<int>  RA(list.begin() + q + 1, list.begin() + r + 1);
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

void  sort(vector<int> &list, int p, int r) {
  if (r - p  > K) {
    int q = (p + r) / 2;
    sort(list, p, q);
    sort(list, q + 1, r);
  }
}

int main(void) {
  vector<int> list = {15 , 87 , 4 , 6 , 9 , 7 , 8};
  
}