/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:51:06 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/26 14:59:51 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongCat();
        WrongCat(const std::string& type);
        WrongCat(const WrongCat &copy);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &c);
        std::string getType() const;
        void makeSound() const;
};

#endif