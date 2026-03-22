#include "Base.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& ref = dynamic_cast<A&>(p);
        (void)ref;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        B& ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        C& ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
}