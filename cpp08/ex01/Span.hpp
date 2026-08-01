#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>

class Span {

private:
  unsigned int _n;
  std::vector<int> _vec;

public:
  Span();
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int n);
  int shortestSpan();
  int longestSpan();

  template <typename Iterator> void addNumbers(Iterator begin, Iterator end) {
    if (std::distance(begin, end) + _vec.size() > _n) {
      throw std::overflow_error("Span is full!");
    }
    _vec.insert(_vec.end(), begin, end);
  }
};

#endif