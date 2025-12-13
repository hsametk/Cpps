/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:42:52 by hakotu            #+#    #+#             */
/*   Updated: 2025/12/14 00:43:05 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

static void printHeader(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main( void ) {
    printHeader("Constructors");
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a (default)      = " << a << "\n";
    std::cout << "b (int 10)       = " << b << "\n";
    std::cout << "c (float 42.42)  = " << c << "\n";
    std::cout << "d (copy of b)    = " << d << "\n";

    printHeader("Copy assignment operator");
    a = c;
    std::cout << "a after a = c    = " << a << "\n";

    printHeader("getRawBits / setRawBits");
    std::cout << "b raw bits       = " << b.getRawBits() << "\n";
    Fixed e;
    e.setRawBits(b.getRawBits());
    std::cout << "e setRawBits(b)  = " << e << " (raw=" << e.getRawBits() << ")\n";

    printHeader("toInt / toFloat");
    std::cout << "c toFloat        = " << c.toFloat() << "\n";
    std::cout << "c toInt          = " << c.toInt() << "\n";

    printHeader("Comparisons");
    Fixed x(5);
    Fixed y(5.5f);

    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "x >  y  : " << (x >  y) << "\n";
    std::cout << "x <  y  : " << (x <  y) << "\n";
    std::cout << "x >= y  : " << (x >= y) << "\n";
    std::cout << "x <= y  : " << (x <= y) << "\n";
    std::cout << "x == y  : " << (x == y) << "\n";
    std::cout << "x != y  : " << (x != y) << "\n";

    printHeader("Arithmetic operators + - * /");
    Fixed p(2);
    Fixed q(3.5f);

    std::cout << "p = " << p << ", q = " << q << "\n";
    std::cout << "p + q = " << (p + q) << "\n";
    std::cout << "p - q = " << (p - q) << "\n";
    std::cout << "p * q = " << (p * q) << "\n";

    std::cout << "p / q = " << (p / q) << "\n";

    printHeader("Pre-increment / Pre-decrement");
    Fixed inc(1);

    std::cout << "inc        = " << inc << "\n";
    std::cout << "++inc      = " << ++inc << "\n"; 
    std::cout << "inc after  = " << inc << "\n";
    std::cout << "--inc      = " << --inc << "\n";
    std::cout << "inc after  = " << inc << "\n";

    printHeader("Post-increment / Post-decrement");
    Fixed post(1);

    std::cout << "post       = " << post << "\n";
    std::cout << "post++     = " << post++ << "\n";
    std::cout << "post after = " << post << "\n";
    std::cout << "post--     = " << post-- << "\n";
    std::cout << "post after = " << post << "\n";

    printHeader("min / max (non-const)");
    Fixed m1(10);
    Fixed m2(20);

    std::cout << "m1 = " << m1 << ", m2 = " << m2 << "\n";
    std::cout << "min(m1,m2) = " << Fixed::min(m1, m2) << "\n";
    std::cout << "max(m1,m2) = " << Fixed::max(m1, m2) << "\n";

    Fixed::min(m1, m2) = Fixed(999);
    std::cout << "After: min(m1,m2)=999\n";
    std::cout << "m1 = " << m1 << ", m2 = " << m2 << "\n";

    printHeader("min / max (const)");
    const Fixed cm1(10);
    const Fixed cm2(20);

    std::cout << "cm1 = " << cm1 << ", cm2 = " << cm2 << "\n";
    std::cout << "min(cm1,cm2) = " << Fixed::min(cm1, cm2) << "\n";
    std::cout << "max(cm1,cm2) = " << Fixed::max(cm1, cm2) << "\n";

    printHeader("End");
    return 0;
}