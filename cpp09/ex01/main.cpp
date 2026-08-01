#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    RPN rpn;
    try
    {
        rpn.calculate(av[1]);
    }
    catch (const std::exception &e)
    {
        (void)e;
        std::cerr << "Error" << std::endl;
        return (1);
    }
    return (0);
}
