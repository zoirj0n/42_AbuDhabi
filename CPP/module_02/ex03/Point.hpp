/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:35:32 by zosobiro          #+#    #+#             */
/*   Updated: 2023/03/16 01:35:33 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point( const float x, const float y );
    Point( const Point &src );
    ~Point();

    Point&  operator=( const Point &rhs );

    Fixed getX( void ) const ;
    Fixed getY( void ) const ;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point );


#endif // POINT_HPP