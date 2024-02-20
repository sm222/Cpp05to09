#pragma once

#ifndef RPN_HPP_
#define RPN_HPP_

# include <iostream>
# include <algorithm>
# include <stack>

using std::stack;

// Class declaration
class RPN {
  public:
    RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &rhs);
    ~RPN(void);
  private:
    //
    stack<int>  _args;
};

#endif // RPN_HPP_


# include <iostream>
# include <algorithm>
# include <stack>
