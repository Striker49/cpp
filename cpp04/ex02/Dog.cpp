#include "AAnimal.hpp"
#include "Dog.hpp"

Dog::Dog( void ) : AAnimal(), _type("Dog")
{
	std::cout << GREEN << "A dog has been revealed" << WHITE << std::endl;
	this->_brain = new Brain;
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << GREEN << "A dog has been reverted to a basic AAnimal" << WHITE << std::endl;
}

Dog::Dog( Dog const& src )
{
	Dog* copy = new Dog;
	copy->_type = src._type;
	copy->_brain = src._brain;
	*this = *copy;
}

Dog& Dog::operator=( Dog const& rhs )
{
	if (this != &rhs)
	{
		Dog* copy = new Dog;
		copy->_type = rhs._type;
		copy->_brain = rhs._brain;
		*this = *copy;
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
