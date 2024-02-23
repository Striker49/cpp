#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
}

void AAnimal::makeSound( void ) const
{
	std::cout << "*AAnimal sound*" << std::endl;
}

std::string AAnimal::getType() const
{
	return(this->_type);
}
