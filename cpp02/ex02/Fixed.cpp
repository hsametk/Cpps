/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:42:57 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/14 00:56:37 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() {
    this->_raw = 0;
}

Fixed::Fixed(const int number)
{
    this->_raw = number << _fracBits;
}

Fixed::Fixed(const float number)
{
    const int scale = 1 << _fracBits;
    float tmp = number * scale;
    float rounded = roundf(tmp);
    _raw = (int)rounded;
}
Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
    if (this != &rhs)
        this->_raw = rhs._raw;
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

float Fixed::toFloat(void) const {
    return (float)_raw / (1 << _fracBits);
}

int Fixed::toInt(void) const {
    return (this->_raw >> this->_fracBits);
}

bool Fixed::operator>(const Fixed&rhs) const {
    return (this->_raw > rhs._raw);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return (this->_raw < rhs._raw);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return (this->_raw >= rhs._raw);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return (this->_raw <= rhs._raw);
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return (this->_raw == rhs._raw);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return (this->_raw != rhs._raw);
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    
    result._raw = this->_raw + rhs._raw;
    return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    
    result._raw = this->_raw - rhs._raw;
    return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    
    result._raw = ((long)this->_raw * (long)rhs._raw) >> _fracBits;
    return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result;
    
    result._raw = (((long)this->_raw) << _fracBits) / rhs._raw;
    return (result);
}

Fixed& Fixed::operator++() 
{
    this->_raw++;
    return (*this);
}

Fixed& Fixed::operator--() 
{
    this->_raw--;
    return (*this);
}

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    this->_raw++;
    return (temp);
}

Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    this->_raw--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a.getRawBits() <= b.getRawBits()) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.getRawBits() <= b.getRawBits()) ? a : b;
    
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a.getRawBits() >= b.getRawBits()) ? a : b;

}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.getRawBits() >= b.getRawBits()) ? a : b;

}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed::~Fixed() {
}