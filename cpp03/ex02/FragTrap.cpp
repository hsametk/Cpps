/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:19:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/13 00:04:45 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("default")
{
    _hit_points = 100;
    _energy_points = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{   
    _hit_points = 100;
    _energy_points = 100;
    _attackDamage = 3,,,,,,,,0;
    std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap &copy)
    : ClapTrap(copy)
{
    std::cout << "FragTrap " << _name << " copy-constructed\n";
}

FragTrap& FragTrap::operator=(const FragTrap &c)
{
    std::cout << "FragTrap copy assignment operator called\n";
    if (this != &c)
        ClapTrap::operator=(c);

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
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
				<< " points of damage!\n";
}