#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>
#include <exception>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

protected:
    virtual void executeAction() const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    const std::string& getTarget() const;
    
    class OpenFileExeption : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif