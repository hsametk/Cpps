
#include "ScalarConverter.hpp"
#include <climits>
#include <cfloat>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cctype>

ScalarConverter::eType ScalarConverter::detectType(const std::string& str)
{
	if (str.empty())
		return INVALID;
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return PSEUDO_FLOAT;
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return PSEUDO_DOUBLE;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;
	if (isIntLiteral(str))
		return INT;
	if (isFloatLiteral(str))
		return FLOAT;
	if (isDoubleLiteral(str))
		return DOUBLE;
	return INVALID;
}

void ScalarConverter::printPseudo(const std::string& str, eType type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == PSEUDO_FLOAT)
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

void ScalarConverter::printChar(const std::string& str)
{
	std::cout << "char: " << str << std::endl;
	std::cout << "int: " << static_cast<int>(str[1]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[1])<< ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[1])<< ".0" << std::endl;
}

void ScalarConverter::printInt(const std::string& str)
{
    int i = std::atoi(str.c_str());
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    if (std::fmod(f, 1.0f) == 0.0f && std::abs(f) < 1e6f)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::fmod(d, 1.0) == 0.0 && std::abs(d) < 1e6)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printFloat(const std::string& str)
{
    float f = std::atof(str.c_str());
    double d = static_cast<double>(f);

    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    if (std::isnan(f) || std::isinf(f)
        || f < std::numeric_limits<int>::min()
        || f > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    if (std::fmod(f, 1.0f) == 0.0f && std::abs(f) < 1e6f)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::fmod(d, 1.0) == 0.0 && std::abs(d) < 1e6)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::printDouble(const std::string& str)
{
    double d = std::atof(str.c_str());

    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (std::isnan(d) || std::isinf(d)
        || d < std::numeric_limits<int>::min()
        || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    if (std::isnan(d) || std::isinf(d)
        || d < -std::numeric_limits<float>::max()
        || d > std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        float f = static_cast<float>(d);
        if (std::fmod(f, 1.0f) == 0.0f && std::abs(f) < 1e6f)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }

    if (std::fmod(d, 1.0) == 0.0 && std::abs(d) < 1e6)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	eType type = detectType(str);

	switch (type)
	{
		case PSEUDO_FLOAT:
		case PSEUDO_DOUBLE:
			printPseudo(str, type);
			break;
		case CHAR:
			printChar(str);
			break;
		case INT:
			printInt(str);
			break;
		case FLOAT:
			printFloat(str);
			break;
		case DOUBLE:
			printDouble(str);
			break;
		case INVALID:
			std::cout << "Invalid input" << std::endl;
			break;
	}
}