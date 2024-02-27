#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("Animal")
{
	std::cout << YELLOW << "An animal has been created" << WHITE << std::endl;
}

AAnimal::AAnimal( AAnimal const& src)
{
	*this = src;
}

AAnimal& AAnimal::operator=( AAnimal const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << YELLOW << "An animal has been killed" << WHITE << std::endl;
}

void AAnimal::makeSound( void ) const
{
	std::cout << "*AAnimal sound*" << std::endl;
}

std::string AAnimal::getType() const
{
	return(this->_type);
}
