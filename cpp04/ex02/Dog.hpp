/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:20:26 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 17:47:56 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    protected:
        std::string _type;
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const std::string& type);
        Dog(const Dog &copy);
        virtual ~Dog();

    Dog &operator=(const Dog &c);
    std::string getType() const;
    virtual void makeSound() const;
    Brain* getBrain() const;
    void setIdea(int index, const std::string& idea);
    void getIdeas() const;
};
#endif