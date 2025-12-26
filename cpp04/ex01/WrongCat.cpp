/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:51:09 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:52:48 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : _type("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : _type(type)
{
    std::cout << "WrongCat constructor called" << std::endl;    
}

WrongCat::WrongCat(const WrongCat &copy) : _type(copy._type)
{
     std::cout << "WrongCat " << _type << " copy-constructed"  << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &c)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        _type = c._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
    return _type;
}

void WrongCat::makeSound() const
{
    std::cout << "Miyav Miyav" << std::endl;
}