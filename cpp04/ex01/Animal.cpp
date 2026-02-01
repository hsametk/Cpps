/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:54:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:16:03 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
    
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
     std::cout << "Animal " << _type << " copy-constructed"  << std::endl;
}

Animal& Animal::operator=(const Animal &c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
    
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Animal" << std::endl;
}