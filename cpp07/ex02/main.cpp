#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> numbers(5);

        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        Array<int> copy(numbers);
        copy[0] = 999;

        std::cout << "Original first element: " << numbers[0] << std::endl;
        std::cout << "Copy first element: " << copy[0] << std::endl;

        Array<std::string> words(3);
        words[0] = "42";
        words[1] = "Türkiye";
        words[2] = "Istanbul";

        std::cout << "String array: ";
        for (unsigned int i = 0; i < words.size(); i++)
            std::cout << words[i] << " ";
        std::cout << std::endl;

        std::cout << numbers[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}