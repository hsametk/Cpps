#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &c)
{
    if (this != &c)
        this->_grade = c._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << '\n';
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

// ✅ ex02: executeForm(AForm const&)
void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << '\n';
    }
}

// ✅ ex02: signForm(AForm &)
void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << '\n';
    }
}
