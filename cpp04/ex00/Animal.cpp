#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	std::cout << "An animal has been created" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "An animal has been killed" << std::endl;
}

Animal::Animal( Animal const& src)
{
	*this = src;
}

Animal& Animal::operator=( Animal const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Animal::makeSound( void ) const
{
	std::cout << "*Animal sound*" << std::endl;
}

std::string Animal::getType() const
{
	return(this->_type);
}
