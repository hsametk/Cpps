/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:26:18 by hakotu            #+#    #+#             */
/*   Updated: 2025/11/21 15:38:03 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
	Fixed const _y;
public:
    Point();
    Point(float x, float y);
	Point(Point const &other);

	Point &operator=(Point const &other);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
};

#endif
