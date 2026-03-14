
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

class ScalarConverter
{
    private:
        ScalarConverter(/* args */);
        ~ScalarConverter();
    public:
        static void convert(const std::string &input);
};

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}

#endif