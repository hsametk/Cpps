
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _sign_grade(150), _execute_grade(150)
{}

AForm::AForm(const std::string& name, const int sign_grade, const int execute_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (_sign_grade < 1 || _execute_grade < 1)
        throw GradeTooHighException();
    if (_sign_grade > 150 || _execute_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _is_signed(copy._is_signed), _sign_grade(copy._sign_grade),
     _execute_grade(copy._execute_grade)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    return *this;
}

AForm::~AForm()
{}

const std::string&	AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _is_signed;
}

int AForm::getSignGrade() const
{
    return _sign_grade;
}

int AForm::getExecuteGrade() const
{
    return _execute_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _sign_grade)
        _is_signed = true;
    else
        throw GradeTooLowException();

}
std::ostream &operator<<(std::ostream &os,  AForm const &Aform)
{
	os << "Name: " << Aform.getName() << " isSigned: " << Aform.getIsSigned() 
    << " SignGrade: " << Aform.getSignGrade() << " ExecuteGrade: " << Aform.getExecuteGrade() << std::endl;
	return (os);
}


const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form Not Signed");
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!_is_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execute_grade)
        throw GradeTooLowException();
    executeAction();
}
