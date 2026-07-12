#include "easyfind.hpp"
int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(100);
    v.push_back(1000);

    try {
        std::vector<int>::iterator it = easyfind(v, 100);
        std::cout << "Value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}