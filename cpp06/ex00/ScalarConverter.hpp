
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {
private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter(void);
  ScalarConverter &operator=(ScalarConverter const &rhs);

  typedef void (*ConvertFunc)(const std::string&);

  static int detectType(const std::string &str);
  static void printChar(const std::string &str);
  static void printInt(const std::string &str);
  static void printFloat(const std::string &str);
  static void printDouble(const std::string &str);
  static void printPseudoFloat(const std::string &str);
  static void printPseudoDouble(const std::string &str);
  static void printInvalid(const std::string &str);
  static bool isIntLiteral(const std::string &str);
  static bool isDoubleLiteral(const std::string &str);
  static bool isFloatLiteral(const std::string &str);

public:
  static void convert(const std::string &str);
};

#endif