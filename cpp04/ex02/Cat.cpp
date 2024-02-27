#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat( void ) : AAnimal(), _type("Cat")
{
	std::cout << BLUE << "A cat has been revealed" << WHITE << std::endl;
	this->_brain = new Brain;
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << BLUE << "A cat has been reverted to a basic AAnimal" << WHITE << std::endl;
}

Cat::Cat( Cat const& src )
{
	Cat* temp = new Cat;
	temp = new Cat;
	temp->_type = src._type;
	*this = *temp;
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
