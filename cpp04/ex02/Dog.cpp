/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:22:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 17:47:53 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const std::string& type) : _type(type)
{
    std::cout << "Dog constructor called" << std::endl;    
    brain = new Brain();
}

Dog::Dog(const Dog &copy) : _type(copy._type)
{
     std::cout << "Dog " << _type << " copy-constructed"  << std::endl;
     brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog &c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
        delete brain;
        brain = new Brain(*c.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

std::string Dog::getType() const
{
    return _type;
}

void Dog::makeSound() const
{
    std::cout << "Hav Hav" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}

void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

void Dog::getIdeas() const
{
    for (int i = 0; i < 100; ++i)
    {
        std::string idea = brain->getIdea(i);
        if (!idea.empty())
        {
            std::cout << "Idea " << i << ": " << idea << std::endl;
        }
    }
}