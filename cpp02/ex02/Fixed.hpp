/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:42:54 by hakotu            #+#    #+#             */
/*   Updated: 2025/11/09 15:39:54 by hakotu           ###   ########.fr       */
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

    // ---------- ex02: Comparisons ----------
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // ---------- ex02: Arithmetic ----------
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // ---------- ex02: Increment / Decrement ----------
    // pre-increment / pre-decrement
    Fixed& operator++(); // ++a
    Fixed& operator--(); // --a
    // post-increment / post-decrement
    Fixed  operator++(int); // a++
    Fixed  operator--(int); // a--

    // ---------- ex02: min / max ----------
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 
