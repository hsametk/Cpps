
#include "ScalarConverter.hpp"

void ScalarConverter::printPseudoFloat(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}

void ScalarConverter::printPseudoDouble(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void ScalarConverter::printInvalid(const std::string &str) {
	(void)str;
	std::cout << "Invalid input" << std::endl;
}

static void printScalar(double d) {
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() ||
      d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (std::isnan(d) || std::isinf(d) ||
		d < -std::numeric_limits<float>::max() ||
		d > std::numeric_limits<float>::max()) {
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

void ScalarConverter::printChar(const std::string &str) {
	char c = (str.length() == 3 && str[0] == '\'' && str[2] == '\'') ? str[1] : str[0];
	printScalar(static_cast<double>(c));
}

void ScalarConverter::printInt(const std::string &str) {
	printScalar(std::strtod(str.c_str(), NULL));
}

void ScalarConverter::printFloat(const std::string &str) {
	float f = static_cast<float>(std::strtod(str.c_str(), NULL));
	printScalar(static_cast<double>(f));
}

void ScalarConverter::printDouble(const std::string &str) {
	printScalar(std::strtod(str.c_str(), NULL));
}

