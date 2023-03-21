/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:29:27 by zosobiro          #+#    #+#             */
/*   Updated: 2023/03/15 02:29:29 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// It creates a zombie, name it, and the zombie announces itself.
void    randomChump( std::string name ) {
    Zombie  zombi( name );
    zombi.announce();
}