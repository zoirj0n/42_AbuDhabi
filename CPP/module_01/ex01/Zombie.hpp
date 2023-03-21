/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:29:41 by zosobiro          #+#    #+#             */
/*   Updated: 2023/03/15 02:29:42 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    
private:
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void    announce( void );
    Zombie* newZombie( std::string name );
    void    setName( std::string name );

};

Zombie*    zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP