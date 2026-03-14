#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <exception>
#include <ctime>
#include <cstdlib>
class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

protected:
    virtual void executeAction() const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    const std::string& getTarget() const;
};

#endif