/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:54:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/27 17:45:07 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _type("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string& type) : _type(type)
{
    std::cout << "Cat constructor called" << std::endl;    
}

Cat::Cat(const Cat &copy) : _type(copy._type)
{
     std::cout << "Cat " << _type << " copy-constructed"  << std::endl;
}

Cat& Cat::operator=(const Cat &c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const
{
    return _type;
}

void Cat::makeSound() const
{
    std::cout << "Miyav Miyav" << std::endl;
}