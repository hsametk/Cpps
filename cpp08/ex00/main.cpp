#include "easyfind.hpp"
#include <deque>
#include <iostream>
int main()
{
    std::cout << "--- Testing with std::vector ---" << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(100);
    v.push_back(1000);

    try {
        std::vector<int>::iterator it = easyfind(v, 100);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error searching 42: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> l;
    l.push_back(42);
    l.push_back(21);
    l.push_back(84);

    try {
        std::list<int>::iterator it = easyfind(l, 21);
        std::cout << "Found value in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with std::deque ---" << std::endl;
    std::deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    try {
        std::deque<int>::iterator it = easyfind(d, 20);
        std::cout << "Found value in deque: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}