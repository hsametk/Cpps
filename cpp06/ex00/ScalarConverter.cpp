
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
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return PSEUDO_FLOAT;
	if (str == "nan" || str == "+inf" || str == "-inf")
		return PSEUDO_DOUBLE;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;
	if (str[str.length() - 1] == 'f' && str.find('.') != std::string::npos)
		return FLOAT;
	if (str.find('.') != std::string::npos)
		return DOUBLE;
	return INT;
}

void ScalarConverter::convert(const std::string& str)
{
	eType type = detectType(str);

	if (type == PSEUDO_FLOAT)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::string doubleStr = str.substr(0, str.length() - 1);
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << doubleStr << std::endl;
		return ;
	}
	if (type == PSEUDO_DOUBLE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return ;
	}
}