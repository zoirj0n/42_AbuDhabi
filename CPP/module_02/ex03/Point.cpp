#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
    // std::cout << "Point created" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y) {
    // std::cout << "Point created" << std::endl;
}

Point::Point( const Point &src ) : _x(src._x), _y(src._y) {
    // std::cout << "Point created" << std::endl;
}

Point::~Point() {
    // std::cout << "Point destroyed" << std::endl;
}

Point&  Point::operator=( const Point &rhs ) {
    if ( this != &rhs ) {
        // const_cast< Fixed& >(this->_x) = rhs.getX();
        // const_cast< Fixed& >(this->_y) = rhs.getY();
        ( Fixed ) this->_x = rhs.getX();
        ( Fixed ) this->_y = rhs.getY();
    }
    return *this;
}

Fixed Point::getX( void ) const {
    return this->_x;
}

Fixed Point::getY( void ) const {
    return this->_y;
}