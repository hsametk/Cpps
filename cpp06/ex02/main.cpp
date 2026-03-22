#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::srand(static_cast<unsigned int>(tv.tv_sec * 1000000 + tv.tv_usec));

    for (int i = 0; i < 6; i++)
    {
        Base* obj = generate();

        std::cout << "Via pointer  : ";
        identify(obj);
        std::cout << "Via reference: ";
        identify(*obj);
        std::cout << "---" << std::endl;

        delete obj;
    }
    return 0;
}