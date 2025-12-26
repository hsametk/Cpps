/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:16:12 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 17:47:54 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    protected:
        std::string _type;
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const std::string& type);
        Cat(const Cat &copy);
        virtual ~Cat();
    Cat &operator=(const Cat &c);
    std::string getType() const;
    virtual void makeSound() const;
    Brain* getBrain() const;
    void setIdea(int index, const std::string& idea);
    void getIdeas() const;
};
#endif