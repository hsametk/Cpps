#include "ScalarConverter.hpp"
#include <exception>

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw std::runtime_error("Usage: ./convert <value>");
        ScalarConverter::convert(argv[1]);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...)
    {
        std::cerr << "An unknown error occured." << std::endl;
        return 1;
    }
    
    return 0;
}