/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:54:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 17:47:55 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _type("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const std::string& type) : _type(type)
{
    std::cout << "Cat constructor called" << std::endl;    
    brain = new Brain();
}

Cat::Cat(const Cat &copy) : _type(copy._type)
{
     std::cout << "Cat " << _type << " copy-constructed"  << std::endl;
     brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat &c)
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

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

std::string Cat::getType() const
{
    return _type;
}

void Cat::makeSound() const
{
    std::cout << "Miyav Miyav" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}

void Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

void Cat::getIdeas() const
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