/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:41:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/11/08 15:37:35 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "iostream"
#include <cmath>
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int                 _raw;
    static const int    _fracBits;

public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& rhs);
	~Fixed();

    int		getRawBits(void) const;
    void	setRawBits(int const raw);

    float	toFloat( void ) const;
    int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 
