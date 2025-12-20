/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:19:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 12:42:23 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("default")
{
    _hit_points = 100;
    _energy_points = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{   
    _hit_points = 100;
    _energy_points = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called"  << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
    : ClapTrap(copy)
{
    std::cout << "FragTrap " << _name << " copy-constructed"  << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &c)
{
    std::cout << "FragTrap copy assignment operator called"  << std::endl;
    if (this != &c)
        ClapTrap::operator=(c);

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called"  << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
        if (_hit_points == 0 || _energy_points == 0)
    {
        std::cout << "FragTrap " << _name << " can't attack: no hit points or energy left." << std::endl;
        return ;
    }
    _energy_points--;
	std::cout	<< "FragTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!"  << std::endl;
}