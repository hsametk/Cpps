/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 12:44:30 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "==== BASIC CONSTRUCTION TEST ===="  << std::endl;
    FragTrap f1("Fraggy");
    std::cout << std::endl;

    std::cout << "==== ATTACK TEST ===="  << std::endl;
    f1.attack("Target A");
    f1.attack("Target B");
    std::cout  << std::endl;

    std::cout << "==== HIGH FIVE TEST ====";
    f1.highFivesGuys();
    std::cout  << std::endl;

    std::cout << "==== DAMAGE & REPAIR TEST ===="  << std::endl;
    f1.takeDamage(40);   // HP düşer
    f1.beRepaired(20);   // HP artar
    f1.takeDamage(200);  // HP = 0
    f1.attack("Target C"); // Saldıramamalı
    std::cout  << std::endl;

    std::cout << "==== COPY CONSTRUCTOR TEST ===="  << std::endl;
    FragTrap f2(f1);
    f2.attack("Copy Target");
    std::cout  << std::endl;

    std::cout << "==== ASSIGNMENT OPERATOR TEST ===="  << std::endl;
    FragTrap f3;
    f3 = f1;
    f3.attack("Assigned Target");
    std::cout  << std::endl;

    std::cout << "==== MULTIPLE OBJECTS / SCOPE TEST ===="  << std::endl;
    {
        FragTrap temp("TempFrag");
        temp.highFivesGuys();
        temp.attack("MiniTarget");
    }
    std::cout << "(TempFrag destroyed here)"  << std::endl;
    std::cout << std::endl;

    std::cout << "==== END OF TESTS ===="  << std::endl;
    return 0;
}

