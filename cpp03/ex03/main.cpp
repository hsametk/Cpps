/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 13:40:47 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "===== CONSTRUCTION TEST =====" << std::endl;
    {
        DiamondTrap a("Diamond");
    }

    std::cout << std::endl << "===== BASIC FUNCTION TEST =====" << std::endl;
    {
        DiamondTrap d("Ruby");

        d.attack("Target");
        d.takeDamage(30);
        d.beRepaired(20);
    }

    std::cout << std::endl << "===== whoAmI TEST =====" << std::endl;
    {
        DiamondTrap d("Emerald");
        d.whoAmI();
    }

    std::cout << std::endl << "===== COPY CONSTRUCTOR TEST =====" << std::endl;
    {
        DiamondTrap original("Original");
        DiamondTrap copy(original);

        copy.whoAmI();
    }

    std::cout << std::endl << "===== ASSIGNMENT OPERATOR TEST =====" << std::endl;
    {
        DiamondTrap a("A");
        DiamondTrap b("B");

        b = a;
        b.whoAmI();
    }

    std::cout << std::endl << "===== ENERGY / HP EDGE CASE =====" << std::endl;
    {
        DiamondTrap d("Edge");

        for (int i = 0; i < 50; i++)
            d.attack("Dummy");

        d.attack("Dummy");
        d.beRepaired(10);
    }

    std::cout << std::endl << "===== DESTRUCTION TEST =====" << std::endl;
    return 0;
}
