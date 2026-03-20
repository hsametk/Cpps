
#include "ScalarConverter.hpp"
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
	return (dotFound && digitBeforeDot && digitAfterDot);
}

bool ScalarConverter::isFloatLiteral(const std::string& str)
{
	if (str.length() < 2)
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	return isDoubleLiteral(str.substr(0, str.length() - 1));
}