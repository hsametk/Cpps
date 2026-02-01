/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:31:07 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 13:24:25 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("DEFAULT_clap_name"), ScavTrap("DEFAULT"), FragTrap("DEFAULT"), _name("DEFAULT")
{
    _hit_points = 100;
    _energy_points = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " default constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hit_points = 100;
    _energy_points = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " constructed\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
    std::cout << "DiamondTrap " << _name << " copy-constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &c)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &c)
    {
        ClapTrap::operator=(c);
        this->_name = c._name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
        std::cout << "DiamondTrap name: " << this->_name
            << ", ClapTrap name: " << ClapTrap::_name
            << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}