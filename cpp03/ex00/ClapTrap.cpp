/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:27:15 by hakotu            #+#    #+#             */
/*   Updated: 2025/11/09 17:53:39 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("default"), _hit_points(10), _energy_points(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " default-constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
: _name(copy._name),
  _hit_points(copy._hit_points),
  _energy_points(copy._energy_points),
  _attackDamage(copy._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy-constructed\n";
}

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hit_points(10), _energy_points(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed\n";
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
	std::cout	<< "ClapTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    // 1) Mevcut HP'yi oku
    // 2) amount >= _hit_points ise _hit_points = 0; yoksa _hit_points -= amount
    // 3) Mesaj bas: alınan hasar ve yeni HP
    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage. HP: " << _hit_points << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    // 1) Eğer _hit_points == 0 veya _energy_points == 0 ise mesaj bas ve return
	if (_hit_points == 0 || _energy_points == 0)
		std::cout << "No more energy points or 0 hit point." << std::endl;
    // 2) Aksi halde: _hit_points += amount
	_hit_points += amount;
    // 3) _energy_points -= 1
	_energy_points -= 1;
    // 4) Mesaj bas: onarım miktarı, yeni HP ve EP
    std::cout << "ClapTrap " << _name
              << " repairs itself by " << amount
              << ". HP: " << _hit_points
              << ", EP: " << _energy_points << "\n";
}

ClapTrap::~ClapTrap()
{
        std::cout << "Deconstructor called" << std::endl;
}