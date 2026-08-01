#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
  *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
  if (this != &other) {
    _stack = other._stack;
  }
  return *this;
}

RPN::~RPN() {}

void RPN::calculate(char *input)
{
    for (char *p = input; *p; p++)
    {
        if (*p == ' ')
        {
            continue;
        }
        else if (*p >= '0' && *p <= '9')
        {
            _stack.push(*p - '0');
        }
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            int op1 = _stack.top();
            _stack.pop();
            int op2 = _stack.top();
            _stack.pop();
            if (*p == '+')
                _stack.push(op2 + op1);
            else if (*p == '-')
                _stack.push(op2 - op1);
            else if (*p == '*')
                _stack.push(op2 * op1);
            else
            {
                if (op1 == 0)
                    throw std::runtime_error("Division by zero");
                _stack.push(op2 / op1);
            }
        }
        else
        {
            throw std::runtime_error("Invalid expression");
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    std::cout << _stack.top() << std::endl;
}

