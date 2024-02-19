#pragma once

#ifndef SPAN_HPP_
#define SPAN_HPP_

# include <iostream>
# include <vector>
// Class declaration
class Span {
  public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &rhs);
    ~Span(void);
    //
    void addNumber(int nuber);
    std::vector<int>  getVet(void) const;
    int               getLimit(void) const;
    //
    int      longestSpan(void) const;
    int      shortestSpan(void) const;
  //
  private:
    Span(void);
    unsigned int      _limit;
    std::vector<int>  _vec;
};

#endif // SPAN_HPP_
