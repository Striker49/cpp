#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog( void ) : Animal(), _type("Dog")
{
	std::cout << "A dog has been revealed" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "A dog has been reverted to a basic animal" << std::endl;
}

Dog::Dog( Dog const& src )
{
	*this = src;
}

Dog& Dog::operator=( Dog const& rhs )
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "*Bark* *Bark*" << std::endl;
}

std::string Dog::getType() const
{
	return(this->_type);
}
