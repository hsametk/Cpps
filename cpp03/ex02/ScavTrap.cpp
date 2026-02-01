/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:49:40 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 12:34:06 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("default")
{
    _hit_points = 100;
    _energy_points = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{   
    _hit_points = 100;
    _energy_points = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
    : ClapTrap(copy)
{
    std::cout << "ScavTrap " << _name << " copy-constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &c)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &c)
        ClapTrap::operator=(c);

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." <<std::endl;
}

void ScavTrap::attack(const std::string& target)
{
        if (_hit_points == 0 || _energy_points == 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack: no hit points or energy left." << std::endl;
        return ;
    }
    _energy_points--;
	std::cout	<< "ScavTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!" << std::endl;
}