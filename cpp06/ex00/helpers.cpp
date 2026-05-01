
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str)
{
	static const ConvertFunc table[] = {
		&ScalarConverter::printChar,
		&ScalarConverter::printInt,
		&ScalarConverter::printFloat,
		&ScalarConverter::printDouble,
		&ScalarConverter::printPseudoFloat,
		&ScalarConverter::printPseudoDouble,
		&ScalarConverter::printInvalid,
	};
	table[detectType(str)](str);
}

int ScalarConverter::detectType(const std::string& str)
{
	if (str.empty())
		return 6;
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return 4;
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return 5;
	if (str.length() == 1 && (str[0] < '0' || str[0] > '9'))
		return 0;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return 0;
	if (isIntLiteral(str))
		return 1;
	if (isFloatLiteral(str))
		return 2;
	if (isDoubleLiteral(str))
		return 3;
	return 6;
}
bool ScalarConverter::isIntLiteral(const std::string& str)
{
	size_t i = 0;

	if (str.empty())
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return false;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& str)
{
	if (str.length() < 2)
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	return isDoubleLiteral(str.substr(0, str.length() - 1));
}

bool ScalarConverter::isDoubleLiteral(const std::string& str)
{
	size_t i = 0;
	bool dotFound = false;
	bool digitBeforeDot = false;
	bool digitAfterDot = false;

	if (str.empty())
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return false;
	while (i < str.length())
	{
		if (std::isdigit(str[i]))
		{
			if (!dotFound)
				digitBeforeDot = true;
			else
				digitAfterDot = true;
		}
		else if (str[i] == '.' && !dotFound)
			dotFound = true;
		else
			return false;
		i++;
	}
	return (dotFound && (digitBeforeDot || digitAfterDot));
}
