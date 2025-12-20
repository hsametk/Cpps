/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 13:09:41 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    std::cout << "====== Constructors test ======" << std::endl;
    ClapTrap ct_default;
    ClapTrap ct_named("Clappy");  
    ClapTrap ct_copy(ct_named); 
    ClapTrap ct_assigned;
    ct_assigned = ct_named;

    std::cout << std::endl << "====== Basic actions test ======" << std::endl;
    ClapTrap hero("Hero");
    
    hero.attack("Training Dummy");
    hero.takeDamage(3);
    hero.beRepaired(2);

    std::cout << std::endl << "====== Energy depletion test ======" << std::endl;
    for (int i = 0; i < 12; ++i)
        hero.attack("Dummy");
    std::cout << std::endl << "====== Taking heavy damage (HP -> 0) ======" << std::endl;
    ClapTrap fragile("Fragile");
    fragile.takeDamage(5);
    fragile.takeDamage(10);
    fragile.takeDamage(1);

    std::cout << std::endl << "====== Repair with/without energy / HP ======" << std::endl;
    ClapTrap robot("Robot");
    robot.takeDamage(4);
    robot.beRepaired(3);

    for (int i = 0; i < 10; ++i)
        robot.attack("Target");

    robot.beRepaired(5);

    ClapTrap dead("Dead");
    dead.takeDamage(20);
    dead.beRepaired(10);

    std::cout << std::endl << "====== End of tests ======" << std::endl;
    std::cout << "====== Case 1: Attempt attack / repair with 0 HP ======" << std::endl;
    {
        ClapTrap zeroHP("ZeroHP");
    
        zeroHP.takeDamage(10);
        zeroHP.takeDamage(5);
    
        zeroHP.attack("Dummy");
        zeroHP.beRepaired(5);
    }
    std::cout << std::endl << "====== Case 2: Attempt attack / repair with 0 Energy ======" << std::endl;
    {
        ClapTrap noEnergy("NoEnergy");
    
        for (int i = 0; i < 10; ++i)
            noEnergy.attack("Target");
    
        noEnergy.attack("Target");
        noEnergy.beRepaired(5);
    }
    std::cout << std::endl << "====== Case 3: Lethal single-hit damage ======" << std::endl;
    {
        ClapTrap oneShot("OneShot");
    
        oneShot.takeDamage(100);
        oneShot.takeDamage(1);
    }
    std::cout << std::endl << "====== Case 4: Damage and repair chain while alive ======" << std::endl;
    {
        ClapTrap chain("Chain");
    
        chain.takeDamage(3);
        chain.takeDamage(2);
        chain.beRepaired(4);
        chain.beRepaired(1);
    }
    std::cout << std::endl << "====== End of error tests ======" << std::endl;
    return 0;
}
