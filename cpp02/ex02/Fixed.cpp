/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:42:57 by hakotu            #+#    #+#             */
/*   Updated: 2025/11/08 20:13:29 by hakotu           ###   ########.fr       */
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
    _raw = static_cast<int>(rounded);
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
    
    result._raw = this->_raw * rhs._raw;
    return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed result;
    
    result._raw = this->_raw / rhs._raw;
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
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed::~Fixed() {
        std::cout << "Destructor called" << std::endl;
}