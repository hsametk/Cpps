#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator it = easyfind(v, 2);
    std::cout << *it << std::endl;
}