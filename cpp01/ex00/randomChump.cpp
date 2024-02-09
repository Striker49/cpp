#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    this->_name = name;
    announce();
}
