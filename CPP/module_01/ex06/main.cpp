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