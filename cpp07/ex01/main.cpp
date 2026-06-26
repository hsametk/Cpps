#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

void increment(int &n) {
    n++;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(intArray, 5, increment);
    std::cout << "Incremented int array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    const std::string strArray[] = {"42", "Türkiye", "Ist"};
    std::cout << "Const string array: ";
    iter(strArray, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}