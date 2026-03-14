
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
	public:
		static void	convert(const std::string& str);
};

#endif