/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:19:26 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/17 23:43:53 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
    FragTrap(const std::string& name);
	FragTrap(const FragTrap &copy);
    ~FragTrap();
	
	FragTrap &operator=(const FragTrap &c);
    
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif