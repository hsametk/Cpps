
#include "Bureaucrat.hpp"   
#include "Form.hpp"
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &c)
{
    if (this != &c)
        this->_grade = c._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}
std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t sign "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}