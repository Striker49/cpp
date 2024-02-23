#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat( void ) : Animal(), _type("Cat")
{
	std::cout << "A cat has been revealed" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "A cat has been reverted to a basic animal" << std::endl;
}

Cat::Cat( Cat const& src )
{
	*this = src;
}

Cat& Cat::operator=( Cat const& rhs )
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "*Meow* *Meow*" << std::endl;
}

std::string Cat::getType() const
{
	return(this->_type);
}
