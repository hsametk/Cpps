
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool			  _is_signed;
	const int	      _sign_grade;
	const int		  _execute_grade;

public:
    Form();
    Form(const std::string& name, const int sign_grade, const int execute_grade);
    ~Form();
    void beSigned(const Bureaucrat &bureaucrat);
    void signForm();
};

#endif