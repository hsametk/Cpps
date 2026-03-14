#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << shrub;
    std::cout << robo;
    std::cout << pardon;

    title("TRY EXECUTE UNSIGNED FORMS");
    boss.executeForm(shrub);
    boss.executeForm(robo);
    boss.executeForm(pardon);

    title("TRY SIGN WITH LOW GRADE");
    low.signForm(shrub);
    low.signForm(robo);
    low.signForm(pardon);

    title("SIGN FORMS");

    mid.signForm(shrub);
    mid.signForm(robo);
    mid.signForm(pardon);
    boss.signForm(pardon);

    title("EXECUTE WITH INSUFFICIENT GRADE");

    low.executeForm(shrub);
    mid.executeForm(robo);
    mid.executeForm(pardon);

    title("EXECUTE WITH BOSS");

    boss.executeForm(shrub);

    boss.executeForm(robo);
    boss.executeForm(robo);
    boss.executeForm(robo);

    boss.executeForm(pardon);
    title("DONE");
    return 0;
}
