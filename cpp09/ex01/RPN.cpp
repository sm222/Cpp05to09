#include "RPN.hpp"
#include <cstring>

static void action(stack<int> &st, char ar) {
  if (st.size() < 2)
    throw std::invalid_argument("invalid");
  int nb[2];
  nb[1] = st.top();
  st.pop();
  nb[0] = st.top();
  st.pop();
  switch (ar) {
  case '+':
    st.push(nb[0] + nb[1]);
    break;
  case '-':
    st.push(nb[0] - nb[1]);
    break;
  case '*':
    st.push(nb[0] * nb[1]);
    break;
  case '/':
    if (nb[0] == 0 || nb[1] == 0)
      throw std::range_error("can't devide by 0");
    else
      st.push(nb[0] / nb[1]);
    break;
  default: {};
  }
}

void  RPN::calculate(void) {
  for (size_t i = 0; i < _input.length(); i++) {
    if (_input[i] == ' ')
      continue ;
    if (std::isdigit(_input[i])) {
      _args.push((int)_input[i] - '0');
    }
    if (std::strchr("+-*/", _input[i]))
      action(_args, _input[i]);
  }
  if (_args.size() > 1)
    throw std::length_error("bad args");
}

// Default constructor
RPN::RPN(void) {}

RPN::RPN(string input) : _input(input) {
  for (size_t i = 0; i < _input.length(); i++) {
    if (!std::isdigit(_input[i]) && !std::strchr("+-*/ ", _input[i]))
      throw std::invalid_argument("invalid char");
  }
}

void RPN::printTop(void) {
  if (_args.size() != 1)
    throw std::invalid_argument("stack is bad");
  std::cout << _args.top() << std::endl;
}

// Copy constructor
RPN::RPN(const RPN &other) {
  *this = other;
}

// Copy assignment overload
RPN &RPN::operator=(const RPN &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
RPN::~RPN(void) {}
