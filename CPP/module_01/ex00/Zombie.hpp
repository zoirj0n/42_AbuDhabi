/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:29:32 by zosobiro          #+#    #+#             */
/*   Updated: 2023/03/15 02:29:33 by zosobiro         ###   ########.fr       */
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
    Zombie( std::string name );
    ~Zombie();
    void    announce( void );
    Zombie* newZombie( std::string name );
    void    randomChump( std::string name );

};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif // ZOMBIE_HPP