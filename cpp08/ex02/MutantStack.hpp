
#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

# include <iostream>
# include <stack>

// Class declaration
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
  public: 
    MutantStack(void) : MutantStack<T, Container>::stack(){};
    MutantStack(const MutantStack<T, Container> &other) :
    MutantStack<T, Container>::std::stack(other){};
    MutantStack &operator=(const MutantStack<T, Container> &rhs) {
      if (this != rhs)
        MutantStack<T, Container>::std::stack::operator=(rhs);
      return (*this);
    };
    virtual ~MutantStack(void){};
  //-                                                   //
  typename Container::iterator begin(void) {
    return (Container::c.begin());
  }
  typename Container::iterator end(void) {
    return (Container::c.end());
  }
  typename Container::reverse_iterator rbegin(void) {
    return (Container::c.rbegin());
  }
  typename Container::reverse_iterator rend(void) {
    return (Container::c.rend());
  }
};

#endif // MUTANTSTACK_HPP_
