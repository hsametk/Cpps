/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:31:11 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/17 23:42:01 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
	    DiamondTrap();
        DiamondTrap(const std::string& name);
	    DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();
	
	DiamondTrap &operator=(const DiamondTrap &c);
    
    void attack(const std::string& target);
    void whoAmI(); 
};

#endif  