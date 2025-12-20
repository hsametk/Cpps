/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 13:13:25 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Samet");
    d.whoAmI();
    
    for (int i = 0; i < 51; i++)
        d.attack("target");
    
    d.whoAmI();
    
    std::cout << "\n==== HP -> 0 TEST ====\n";
    d.takeDamage(1000);
    d.attack("target");
    d.whoAmI();
}

