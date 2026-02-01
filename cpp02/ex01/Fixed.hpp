/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:41:45 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/14 00:56:56 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "string.h"
#include "iostream"
#include <cmath>

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
const Fixed &max(const Fixed &a, const Fixed &b);

#endif
