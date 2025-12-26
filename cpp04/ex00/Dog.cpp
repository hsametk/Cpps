/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:22:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:22:27 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _type("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string& type) : _type(type)
{
    std::cout << "Dog constructor called" << std::endl;    
}

Dog::Dog(const Dog &copy) : _type(copy._type)
{
     std::cout << "Dog " << _type << " copy-constructed"  << std::endl;
}

Dog& Dog::operator=(const Dog &c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const
{
    return _type;
}

void Dog::makeSound() const
{
    std::cout << "Hav Hav" << std::endl;
}