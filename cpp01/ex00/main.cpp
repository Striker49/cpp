#include "Zombie.hpp"

int main(void)
{
    Zombie* Nathan;

    randomChump("Bob");
    randomChump("Bob2");
    randomChump("Bob3");
    Nathan = newZombie("Nathan");

    delete Nathan;
    
    return (0);
}
