/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 13:11:30 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "==== BASIC CONSTRUCTION TEST ====" << std::endl;
    ScavTrap s1("Guardian");
    std::cout << std::endl;

    std::cout << "==== ATTACK TEST ===="  << std::endl;
    s1.attack("Enemy");
    s1.attack("Enemy");
    std::cout  << std::endl;

    std::cout << "==== GUARD MODE TEST ===="  << std::endl;
    s1.guardGate();
    std::cout  << std::endl;

    std::cout << "==== DAMAGE & REPAIR TEST ===="  << std::endl;
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.takeDamage(200);
    s1.attack("Enemy");
    std::cout << std::endl;

    std::cout << "==== COPY CONSTRUCTOR TEST ===="  << std::endl;
    ScavTrap s2(s1);
    s2.attack("Target Copy");
    std::cout  << std::endl;

    std::cout << "==== ASSIGNMENT OPERATOR TEST ===="  << std::endl;
    ScavTrap s3;
    s3 = s1;
    s3.attack("Target Assigned");
    std::cout << std::endl;

    std::cout << "==== MULTIPLE OBJECT TEST ===="  << std::endl;
    {
        ScavTrap temp("TempGuard");
        temp.guardGate();
        temp.attack("Intruder");
    }
    std::cout << "(TempGuard destroyed here)";
    std::cout << std::endl;

    std::cout << "==== END OF TESTS ===="  << std::endl;
    return 0;
}
