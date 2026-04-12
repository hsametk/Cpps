
#include "ScalarConverter.hpp"

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

ScalarConverter::eType ScalarConverter::detectType(const std::string& str)
{
	if (str.empty())
		return INVALID;
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return PSEUDO_FLOAT;
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return PSEUDO_DOUBLE;
	if (str.length() == 1 && (str[0] < '0' || str[0] > '9'))
		return CHAR;
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
