/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:54:02 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 12:47:34 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constroctor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    
}


Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
    
}