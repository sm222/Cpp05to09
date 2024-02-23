#pragma once

#ifndef RPN_HPP_
#define RPN_HPP_

# include <iostream>
# include <algorithm>
# include <stack>

using std::stack;
using std::string;

// Class declaration
class RPN {
  public:
    RPN(string input);
    void  calculate(void);
    void  printTop(void);
    ~RPN(void);
  private:
    RPN &operator=(const RPN &rhs);
    RPN(const RPN &other);
    RPN(void);
    //
    string      _input;
    stack<int>  _args;
};

#endif // RPN_HPP_
