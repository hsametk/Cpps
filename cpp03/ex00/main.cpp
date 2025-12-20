/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 12:27:14 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    std::cout << "====== Constructors test ====== << std::endl";
    ClapTrap ct_default;              // default constructor
    ClapTrap ct_named("Clappy");      // name constructor
    ClapTrap ct_copy(ct_named);       // copy constructor
    ClapTrap ct_assigned;             // default then assignment
    ct_assigned = ct_named;

    std::cout << std::endl << "====== Basic actions test ====== << std::endl";
    ClapTrap hero("Hero");
    
    hero.attack("Training Dummy");    // normal attack
    hero.takeDamage(3);               // takes some damage
    hero.beRepaired(2);               // repairs a bit

    std::cout << std::endl << "====== Energy depletion test ====== << std::endl";
    // Hero'nın bütün enerji puanlarını bitirelim
    for (int i = 0; i < 12; ++i)
        hero.attack("Dummy");         // EP 0'a düşünce saldırı yapamamalı

    std::cout << std::endl << "====== Taking heavy damage (HP -> 0) ====== << std::endl";
    ClapTrap fragile("Fragile");
    fragile.takeDamage(5);
    fragile.takeDamage(10);           // burada HP 0'a inmeli
    fragile.takeDamage(1);            // zaten 0 HP iken nasıl davrandığını gör

    std::cout << std::endl << "====== Repair with/without energy / HP ====== << std::endl";
    ClapTrap robot("Robot");

    // Biraz hasar alıp sonra tamir olsun
    robot.takeDamage(4);
    robot.beRepaired(3);

    // Enerjiyi sıfırlayalım
    for (int i = 0; i < 10; ++i)
        robot.attack("Target");

    // EP 0 iken tamir denemesi
    robot.beRepaired(5);

    // HP 0 iken tamir denemesi
    ClapTrap dead("Dead");
    dead.takeDamage(20);              // HP 0
    dead.beRepaired(10);              // HP 0 + EP (varsa) durumunda ne oluyor bak

    std::cout << std::endl << "====== End of tests ====== << std::endl";
    std::cout << "====== Case 1: 0 HP iken attack / repair denemesi ====== << std::endl";
    {
        ClapTrap zeroHP("ZeroHP");

        // HP'yi sıfıra indirelim
        zeroHP.takeDamage(10); // HP -> 0
        zeroHP.takeDamage(5);  // zaten 0 HP iken damage denemesi

        // 0 HP iken attack
        zeroHP.attack("Dummy");

        // 0 HP iken repair
        zeroHP.beRepaired(5);
    }

    std::cout << std::endl << "====== Case 2: 0 Energy iken attack / repair denemesi ====== << std::endl";
    {
        ClapTrap noEnergy("NoEnergy");

        // EP'yi bitir
        for (int i = 0; i < 10; ++i)
            noEnergy.attack("Target");    // 10 enerji harcar

        // EP = 0 iken tekrar attack
        noEnergy.attack("Target");

        // EP = 0 iken repair
        noEnergy.beRepaired(5);
    }

    std::cout << std::endl << "====== Case 3: Tekte öldüren büyük damage ====== << std::endl";
    {
        ClapTrap oneShot("OneShot");

        // 10'dan büyük damage
        oneShot.takeDamage(100);   // HP 0'a sabitlenmeli
        oneShot.takeDamage(1);     // zaten 0 HP iken damage
    }

    std::cout << std::endl << "====== Case 4: HP 0 değilken küçük damage ve repair zinciri ====== << std::endl";
    {
        ClapTrap chain("Chain");

        chain.takeDamage(3);   // HP 7
        chain.takeDamage(2);   // HP 5
        chain.beRepaired(4);   // HP 9, EP 9
        chain.beRepaired(1);   // HP 10, EP 8 (veya senin sistemine göre)
    }

    std::cout << std::endl << "====== End of error tests ====== << std::endl";
    return 0;
}
