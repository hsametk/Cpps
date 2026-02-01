/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:15 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/20 12:12:22 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("default"), _hit_points(10), _energy_points(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " default-constructed" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hit_points(10), _energy_points(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed"  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
: _name(copy._name),
  _hit_points(copy._hit_points),
  _energy_points(copy._energy_points),
  _attackDamage(copy._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy-constructed"  << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &c) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        _name = c._name;
        _hit_points = c._hit_points;
        _energy_points = c._energy_points;
        _attackDamage = c._attackDamage;
    }
    return *this;
}
void	ClapTrap::attack(const std::string& target)
{
    if (_hit_points == 0 || _energy_points == 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack: no hit points or energy left." << std::endl;
        return ;
    }
    _energy_points--;
	std::cout	<< "ClapTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!"  << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name 
          << " can't repair itself: no energy points or hit points left." << std::endl;
        return ;
    }
    _hit_points = (amount >= _hit_points) ? 0 : _hit_points - amount;
    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage. HP: " << _hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0 || _energy_points == 0)
    {
		std::cout << "ClapTrap " << _name << " can't repair itself: no energy points or hit points left." << std::endl;
        return ;
    }
	_hit_points += amount;
	_energy_points -= 1;
    std::cout << "ClapTrap " << _name
              << " repairs itself by " << amount
              << ". HP: " << _hit_points
              << ", EP: " << _energy_points << std::endl;
}

ClapTrap::~ClapTrap()
{
        std::cout << "Destructor called" << std::endl;
}