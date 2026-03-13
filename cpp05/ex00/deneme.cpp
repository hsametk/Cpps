
#include <iostream>
#include <exception>

int main()
{
    try
    {
        throw std::runtime_error("expection");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "program başarıyla sonlandı" << std::endl;
}

//std::logic_error
//std::bad_alloc
//std::bad_cast
//gibi expection türleri vardır.