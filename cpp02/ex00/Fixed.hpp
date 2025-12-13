/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:05:48 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/14 00:57:32 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include "string.h"
#include "iostream"

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
