#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("DEFAULT")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm",145, 137) ,_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream newfile((_target + std::string("_shrubbery")).c_str());
    if (newfile.is_open())
    {
        newfile << "    /\\    \n";
		newfile << "   /  \\   \n";
		newfile << "  /    \\  \n";
		newfile << " /      \\ \n";
		newfile << "/________\\\n";
		newfile << "    ||    \n";
		newfile << "    ||    \n";
		newfile << "    ||    \n";

		newfile.close();
    }
    else
    {
        throw ShrubberyCreationForm::OpenFileExeption();
    }
}

const char *ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
    return("Could'nt open and write the file.");
}