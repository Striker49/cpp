#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie Bob;
    Bob.setName(name);
    Bob.announce();
}
