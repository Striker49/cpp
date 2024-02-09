#include "Zombie.hpp"

int main(void)
{
    Zombie* Bob;
    Zombie* Nathan;

    Bob = zombieHorde(5, "Bob");
    Nathan = zombieHorde(10, "Nathan");

	for (int i = 0; i < 5; i++)
    {
        Bob[i].announce();
    }

    delete [] Bob;
    delete [] Nathan;
    
    return (0);
}