
#include "Form.hpp"
Form::Form() : _name("default"), _is_signed(false), _sign_grade(150), _execute_grade(150)
{}

Form::Form(const std::string& name, const int sign_grade, const int execute_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (_sign_grade < 1 || _execute_grade < 1)
        throw GradeTooHighException();
    if (_sign_grade > 150 || _execute_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _is_signed(copy._is_signed), _sign_grade(copy._sign_grade),
     _execute_grade(copy._execute_grade)
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    return *this;
}

Form::~Form()
{}

const std::string&	Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _is_signed;
}

int Form::getSignGrade() const
{
    return _sign_grade;
}

int Form::getExecuteGrade() const
{
    return _execute_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _sign_grade)
        _is_signed = true;
    else
        throw GradeTooLowException();

}
std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getSignGrade() << " ExecuteGrade: " << form.getExecuteGrade() << std::endl;
	return (os);
}


const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}