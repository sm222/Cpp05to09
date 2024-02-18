#pragma once

#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

# include <stack>
using std::stack;


// Class declaration
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
  public: 
    MutantStack(void) : MutantStack<T, Container>::stack(){};
    MutantStack(const MutantStack<T, Container> &other) :
      MutantStack<T, Container>::stack(other){};
    MutantStack &operator=(const MutantStack<T, Container> &rhs) {
      if (this != rhs)
        MutantStack<T, Container>::std::stack::operator=(rhs);
      return (*this);
    };
    virtual ~MutantStack(void) {};
  //-                                          -//
  typedef typename Container::iterator          iterator;
  typedef typename Container::reverse_iterator  reverse_iterator;

  iterator begin(void) {
    return (this->c.begin()); };
  iterator end(void) {
    return (this->c.end()); };
  reverse_iterator rbegin(void) {
    return (this->c.rbegin()); };
  reverse_iterator rend(void) {
    return (this->c.rend()); };
};

#endif // MUTANTSTACK_HPP_
