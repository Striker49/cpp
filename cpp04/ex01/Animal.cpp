#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	std::cout << YELLOW << "An animal has been created" << WHITE << std::endl;
}

Animal::~Animal( void )
{
	std::cout << YELLOW << "An animal has been killed" << WHITE << std::endl;
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
