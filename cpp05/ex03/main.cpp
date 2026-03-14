#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void title(const std::string& s)
{
    std::cout << "\n========== " << s << " ==========\n";
}

int main()
{
    title("CREATE BUREAUCRATS");
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);
    Bureaucrat low("Low", 150);

    std::cout << boss;
    std::cout << mid;
    std::cout << low;

    title("CREATE FORMS");
    Intern intern;
    AForm* shrub = intern.makeForm("shrubbery creation", "home");
    AForm* robo = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur");

    std::cout << *shrub;
    std::cout << *robo;
    std::cout << *pardon;

    title("TRY EXECUTE UNSIGNED FORMS");
    boss.executeForm(*shrub);
    boss.executeForm(*robo);
    boss.executeForm(*pardon);

    title("TRY SIGN WITH LOW GRADE");
    low.signForm(*shrub);
    low.signForm(*robo);
    low.signForm(*pardon);

    title("SIGN FORMS");

    mid.signForm(*shrub);
    mid.signForm(*robo);
    mid.signForm(*pardon);
    boss.signForm(*pardon);

    title("EXECUTE WITH INSUFFICIENT GRADE");

    low.executeForm(*shrub);
    mid.executeForm(*robo);
    mid.executeForm(*pardon);

    title("EXECUTE WITH BOSS");

    boss.executeForm(*shrub);

    boss.executeForm(*robo);
    boss.executeForm(*robo);
    boss.executeForm(*robo);

    boss.executeForm(*pardon);

    title("HEAP-ALLOCATED INTERN");
    Intern *z = new Intern();
    AForm *heapForm = z->makeForm("presidential pardon", "Clown");
    if (heapForm)
    {
        std::cout << *heapForm;
        boss.signForm(*heapForm);
        boss.executeForm(*heapForm);
        delete heapForm;
    }
    delete z;

    title("DONE");

    delete shrub;
    delete robo;
    delete pardon;

    return 0;
}
