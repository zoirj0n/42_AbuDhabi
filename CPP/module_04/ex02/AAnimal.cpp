/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:02:55 by zosobiro          #+#    #+#             */
/*   Updated: 2023/03/21 12:02:56 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "AAnimel" ) {
    std::cout << this->_type << " constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type( type )
{
    std::cout << "AAnimal " << this->_type << " constructor called" << std::endl;
}

AAnimal::~AAnimal( void )
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& src )
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=( const AAnimal& rhs )
{
    std::cout << "<AAnimal.cpp:35: AAnimal assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->_type = rhs._type;
    }
    return *this;
}

void AAnimal::makeSound( void ) const
{
    std::cout << "AAnimal makeSound called" << std::endl;
}

std::string    AAnimal::getType( void ) const
{
    return this->_type;
}