/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:30:38 by zosobiro          #+#    #+#             */
/*   Updated: 2023/03/15 02:30:39 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"



int main( int ac, char **av ) {

    if (ac != 2) {
        return (std::cout << "Usage: ./harlFilter \"level\"\n", EXIT_FAILURE);
    }
    std::string input = av[1];
    Harl        harl;

    harl.complain(input);

    return EXIT_SUCCESS;
}