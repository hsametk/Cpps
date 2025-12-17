/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:49:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/17 23:44:04 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
    ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap &copy);
    ~ScavTrap();
	
	ScavTrap &operator=(const ScavTrap &c);
    
    void attack(const std::string& target);
    void guardGate();
};

#endif