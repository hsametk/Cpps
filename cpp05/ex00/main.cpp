
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat samcu("Samet",1);
	std::cout << samcu;
	try
	{
		samcu.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << samcu;
	std::cout << "--------------" << "\n";
	try
	{
		Bureaucrat wrong("Harwey Specter", 1500);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "--------------" << "\n";
	try
	{
		Bureaucrat low("Mike Ross", -11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "--------------" << "\n";
	Bureaucrat Louis("Louis Litt", 2);
	Louis.incrementGrade();
	std::cout << Louis;
	try
	{
		Louis.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Louis;
	std::cout << "--------------" << "\n";
	std::cout << Louis.getName() << std::endl;
	std::cout << Louis.getGrade() << std::endl;

	return (0);
}