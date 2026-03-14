#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool              _is_signed;
    const int         _sign_grade;
    const int         _execute_grade;

protected:
    virtual void executeAction() const = 0;

public:
    AForm();
    AForm(const std::string& name, int sign_grade, int execute_grade);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;
    int                getExecuteGrade() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const& executor) const;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, AForm const &other);

#endif
