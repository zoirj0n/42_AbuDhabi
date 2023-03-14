#include "Zombie.hpp"

#define N 4

int main( void ) {
    Zombie *zombiz = zombieHorde(N, "zombi");

    for (size_t i = 0; i < N; i++) {
        zombiz[i].announce();
    }

    delete [] zombiz;
    return 0;
}