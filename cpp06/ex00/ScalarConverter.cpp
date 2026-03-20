
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
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return PSEUDO_FLOAT;
	if (str == "nan" || str == "+inf" || str == "-inf")
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
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << i << ".0f" << std::endl;
    std::cout << "double: " << i << ".0" << std::endl;
}

void ScalarConverter::printFloat(const std::string& str)
{
	std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0])<< ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0])<< ".0" << std::endl;

}

void ScalarConverter::printDouble(const std::string& str)
{
	std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0])<< ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0])<< ".0" << std::endl;

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
//TODO:enum a INVALID eklenecek detectype en son int te bitmeyecek.
//TODO:isIntLiteral(str) isFloatLiteral(str) isDoubleLiteral(str) bu fonksiyonların yazılması lazım.
//TODO:
/*
Mantık nasıl olmalı?
isIntLiteral

Geçerli örnekler:

0

42

-42

+42 istersen kabul edebilirsin

Kurallar:

başta opsiyonel + / -

geri kalan tüm karakterler digit olmalı

en az bir digit olmalı

isFloatLiteral

Geçerli örnekler:

0.0f

42.0f

-4.2f

Kurallar:

son karakter f

sondaki f hariç içerikte tam bir decimal sayı olmalı

bir tane . olmalı

.’nin iki yanında da en az bir digit olmalı

başta opsiyonel sign olabilir

Yani:

4.2f geçerli

.2f bence alma

4.f bence alma

42ff alma

..f alma

isDoubleLiteral

Geçerli örnekler:

0.0

42.0

-4.2

Kurallar:

float ile aynı ama sonda f yok
*/
//TODO: Max int i handle lamam lazım.
