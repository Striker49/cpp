#include "Zombie.hpp"

int main(void)
{
    Zombie Bob;
    Zombie* Nathan;

    Bob.randomChump("Bob");
    Bob.randomChump("Bob");
    Bob.randomChump("Bob");
    Nathan = newZombie("Nathan");

    delete Nathan;
    
    return (0);
}