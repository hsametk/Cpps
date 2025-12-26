/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:20:26 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:20:03 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
    protected:
        std::string _type;
    public:
        Dog();
        Dog(const std::string& type);
        Dog(const Dog &copy);
        virtual ~Dog();

    Dog &operator=(const Dog &c);
    std::string getType() const;
    virtual void makeSound() const;
};
#endif