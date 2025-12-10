/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/11 02:30:44 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "==== BASIC CONSTRUCTION TEST ====\n";
    ScavTrap s1("Guardian");
    std::cout << "\n";

    std::cout << "==== ATTACK TEST ====\n";
    s1.attack("Enemy");
    s1.attack("Enemy");
    std::cout << "\n";

    std::cout << "==== GUARD MODE TEST ====\n";
    s1.guardGate();
    std::cout << "\n";

    std::cout << "==== DAMAGE & REPAIR TEST ====\n";
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.takeDamage(200); // HP -> 0
    s1.attack("Enemy"); // Attack yapamamalı
    std::cout << "\n";

    std::cout << "==== COPY CONSTRUCTOR TEST ====\n";
    ScavTrap s2(s1);
    s2.attack("Target Copy");
    std::cout << "\n";

    std::cout << "==== ASSIGNMENT OPERATOR TEST ====\n";
    ScavTrap s3;
    s3 = s1;
    s3.attack("Target Assigned");
    std::cout << "\n";

    std::cout << "==== MULTIPLE OBJECT TEST ====\n";
    {
        ScavTrap temp("TempGuard");
        temp.guardGate();
        temp.attack("Intruder");
    }
    std::cout << "(TempGuard destroyed here)\n";
    std::cout << "\n";

    std::cout << "==== END OF TESTS ====\n";
    return 0;
}
