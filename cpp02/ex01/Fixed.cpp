/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:41:42 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/05 18:52:50 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"
const int Fixed::_fracBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_raw = 0;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->_raw = number << _fracBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    const int scale = 1 << _fracBits;
    float tmp = number * scale;
    float rounded = roundf(tmp);
    _raw = (int)rounded;
}
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_raw = rhs._raw;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

float Fixed::toFloat(void) const {
    return _raw / 256.0f;
}

int Fixed::toInt(void) const {
    return (this->_raw >> this->_fracBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed::~Fixed() {
        std::cout << "Destructor called" << std::endl;
}