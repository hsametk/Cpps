
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>

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
			PSEUDO_DOUBLE  // nan, +inf, -inf
		};

		static eType	detectType(const std::string& str);

	public:
		static void	convert(const std::string& str);
};

#endif