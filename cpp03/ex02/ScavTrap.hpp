/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:49:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/11 01:57:42 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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