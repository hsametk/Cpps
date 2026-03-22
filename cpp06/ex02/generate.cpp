#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int randomNumber = std::rand() % 3;
    if (randomNumber == 0)
        return new A;
    else if (randomNumber == 1)
        return new B;
    return new C;
}