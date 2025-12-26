/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:16:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:51:35 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    protected:
        std::string _type;
    public:
        Cat();
        Cat(const std::string& type);
        Cat(const Cat &copy);
        virtual ~Cat();
    Cat &operator=(const Cat &c);
    std::string getType() const;
    virtual void makeSound() const;
};
#endif