/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:05:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/13 17:35:06 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "iostream"

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int                 _raw;
    static const int    _fracBits;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();

    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif 
