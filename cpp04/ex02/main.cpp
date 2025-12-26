
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <cstdio>
#include <cstdlib>
int main()
{
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    //meta->makeSound();


    //delete meta;
    delete j;
    delete i;
    std::cout << "----- WrongAnimal Test -----" << std::endl;
    WrongAnimal* wa = new WrongAnimal();
    WrongAnimal* wcat_as_base = new WrongCat();
    std::cout << wcat_as_base->getType() << std::endl;
    wcat_as_base->makeSound(); // prints WrongAnimal sound (NOT WrongCat)
    delete wa;
    delete wcat_as_base;

    std::cout << "----- WrongAnimal Test -----" << std::endl;
    std::cout << "----- WrongAnimal Test -----" << std::endl;
    	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int idx = 0; idx < 10; idx++)
	{
		if (idx % 2)
		{
			meta[idx] = new Cat();
			if (meta[idx] == NULL)
			{
				perror("Cat allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
		else
		{
			meta[idx] = new Dog();
			if (meta[idx] == NULL)
			{
				perror("Dog allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
	}
	std::cout << std::endl;

    	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int idx = 0; idx < 10; idx++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[idx]->getType() << std::endl;
		meta[idx]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int idx = 0; idx < 10; idx++)
		delete(meta[idx]);

    std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	a->setIdea(0, "I have to sniff it");
	a->setIdea(1, "I have to pee on it");
	a->setIdea(2, "I have to sniff it again");
	a->setIdea(101, "some shit");

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);
    return 0;
}