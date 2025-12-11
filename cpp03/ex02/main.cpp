/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/12 00:26:06 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "==== BASIC CONSTRUCTION TEST ====\n";
    FragTrap f1("Fraggy");
    std::cout << "\n";

    std::cout << "==== ATTACK TEST ====\n";
    f1.attack("Target A");
    f1.attack("Target B");
    std::cout << "\n";

    std::cout << "==== HIGH FIVE TEST ====\n";
    f1.highFivesGuys();
    std::cout << "\n";

    std::cout << "==== DAMAGE & REPAIR TEST ====\n";
    f1.takeDamage(40);   // HP düşer
    f1.beRepaired(20);   // HP artar
    f1.takeDamage(200);  // HP = 0
    f1.attack("Target C"); // Saldıramamalı
    std::cout << "\n";

    std::cout << "==== COPY CONSTRUCTOR TEST ====\n";
    FragTrap f2(f1);
    f2.attack("Copy Target");
    std::cout << "\n";

    std::cout << "==== ASSIGNMENT OPERATOR TEST ====\n";
    FragTrap f3;
    f3 = f1;
    f3.attack("Assigned Target");
    std::cout << "\n";

    std::cout << "==== MULTIPLE OBJECTS / SCOPE TEST ====\n";
    {
        FragTrap temp("TempFrag");
        temp.highFivesGuys();
        temp.attack("MiniTarget");
    }
    std::cout << "(TempFrag destroyed here)\n";
    std::cout << "\n";

    std::cout << "==== END OF TESTS ====\n";
    return 0;
}

