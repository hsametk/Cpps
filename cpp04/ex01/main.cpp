/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:33:55 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/27 17:34:26 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
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
    WrongAnimal* wcat = new WrongCat();
    std::cout << wcat->getType() << std::endl;
    wcat->makeSound();
    delete wa;
    delete wcat;

	std::cout << "Constructing" << std::endl;
	const Animal	*meta[10];
	for (int idx = 0; idx < 10; idx++)
	{
		if (idx % 2)
		{
			meta[idx] = new Cat();
			if (meta[idx] == NULL)
			{
				std::cerr << "Cat allocation failed" << std::endl;
				exit(1);
			}
		}
		else
		{
			meta[idx] = new Dog();
			if (meta[idx] == NULL)
			{
				std::cerr << "Dog allocation failed" << std::endl;
				exit(1);
			}
		}
	}
	std::cout << std::endl;

    std::cout << "Testing" << std::endl;
	for (int idx = 0; idx < 10; idx++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[idx]->getType() << std::endl;
		meta[idx]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Deconstructing" << std::endl;
	for (int idx = 0; idx < 10; idx++)
		delete(meta[idx]);

    std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "Constructing" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		std::cout << "Allocation failed" << std::endl;
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
		std::cout << "Allocation failed" << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "Testing a" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdeas();
	std::cout << std::endl;

	std::cout << "Deconstructing a" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "Testing b" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdeas();
	std::cout << std::endl;

	std::cout << "Deconstructing b" << std::endl;
	delete(b);
    return 0;
}