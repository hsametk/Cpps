#include "Span.hpp"

Span::Span()
{
    _n = 0;
}

Span::Span(unsigned int n)
    : _n(n)
{
}

Span::Span(const Span& other)
    : _n(other._n)
    , _vec(other._vec)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other) {
        _n = other._n;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_vec.size() >= _n) {
        throw std::overflow_error("Span is full!");
    }
    _vec.push_back(n);
}

int Span::shortestSpan()
{
    int minSpan;
    std::vector<int> sortedVec;

    if (_vec.size() < 2) {
        throw std::logic_error("Not enough elements to calculate shortest span!");
    }
    sortedVec = _vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    minSpan = sortedVec[1] - sortedVec[0];
    for (size_t i = 2; i < sortedVec.size(); ++i) { //burada size_t kullanmak zorundayım.
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan()
{
    int maxVal;
    int minVal;

    if (_vec.size() < 2) {
        throw std::logic_error("Not enough elements to calculate longest span!");
    }
    minVal = *std::min_element(_vec.begin(), _vec.end());
    maxVal = *std::max_element(_vec.begin(), _vec.end());
    return (maxVal - minVal);
}