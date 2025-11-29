/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:26:20 by hakotu            #+#    #+#             */
/*   Updated: 2025/11/21 15:40:38 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    
}

Point::Point(float x, float y) : _x(x), _y(y)
{
    
}

Point::Point(Point const &other) : _x(other.getX()), _y(other.getY())
{
    
}

Point &Point::operator=(Point const )