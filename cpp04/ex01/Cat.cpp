#include "Cat.hpp"

Cat::Cat( void ) : Animal(), _type("Cat")
{
	std::cout << BLUE << "A cat has been revealed" << WHITE << std::endl;
	this->_brain = new Brain;
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << BLUE << "A cat has been reverted to a basic Aanimal" << WHITE << std::endl;
}

Cat::Cat( Cat const& src )
{
	Cat* copy = new Cat;
	copy->_type = src._type;
	copy->_brain = src._brain;
	*this = *copy;
}

Cat& Cat::operator=( Cat const& rhs )
{
	if (this != &rhs)
	{
		Cat* copy = new Cat;
		copy->_type = rhs._type;
		copy->_brain = rhs._brain;
		*this = *copy;
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
