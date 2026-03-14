
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return (*this); 
}

Intern::~Intern()
{}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    if (name == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (name == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (name == "presidential pardon")
        return new PresidentialPardonForm(target);
    else
    {
        std::cout << "Intern couldn't create form: " << name << std::endl;
        return NULL;
    }
}