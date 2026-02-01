/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:53:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:16:36 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal &copy);
        virtual ~Animal();
	
    Animal &operator=(const Animal &c);
    std::string getType() const;
    virtual void makeSound() const;
};
#endif