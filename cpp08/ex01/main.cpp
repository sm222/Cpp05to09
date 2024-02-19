#include "Span.hpp"

int main(void) {
  // test 1
  try
  {
    size_t N = 10000;
    Span A(N);
    int nb = (N / 2) * -1;
    for (size_t i = 0; i < N; i++)
    {
      A.addNumber(nb++);
    }
    std::cout << "long  " << A.longestSpan() << std::endl;
    std::cout << "short " << A.shortestSpan() << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  // test 2
  try {
    size_t N = 60;
    Span A(N);
    int nb = N;
    for (size_t i = 0; i < N; i++)
    {
      A.addNumber(nb);
      nb *= 2;
    }
    std::cout << "long  " << A.longestSpan() << std::endl;
    std::cout << "short " << A.shortestSpan() << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  // test 3
  Span sp = Span(5);
  sp.addNumber(3);
  sp.addNumber(6);
  sp.addNumber(9);
  sp.addNumber(11);
  sp.addNumber(17);
  std::cout << std::endl;
  std::cout << "long  " << sp.shortestSpan() << std::endl;
  std::cout << "short " << sp.longestSpan() << std::endl;
  return (0);
}