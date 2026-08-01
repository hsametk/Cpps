#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

#include <iostream>
#include <stdexcept>

class RPN {
private:
  std::stack<int> _stack;

public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  void calculate(char *input);
};

#endif