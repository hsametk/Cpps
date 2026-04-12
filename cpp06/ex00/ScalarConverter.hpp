
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
#include <climits>
#include <cfloat>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);

		enum eType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO_FLOAT,  // nanf, +inff, -inff
			PSEUDO_DOUBLE, // nan, +inf, -inf
			INVALID
		};

		static eType	detectType(const std::string& str);
		static void	printPseudo(const std::string& str, eType type);
		static void	printChar(const std::string& str);
		static void	printInt(const std::string& str);
		static void	printFloat(const std::string& str);
		static void	printDouble(const std::string& str);
		static bool isIntLiteral(const std::string& str);
		static bool isDoubleLiteral(const std::string& str);
		static bool isFloatLiteral(const std::string& str);


	public:
		static void	convert(const std::string& str);
};

#endif