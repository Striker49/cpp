#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << "\033[0;31m" << "A Wrong animal has been created" << "\033[0;37m" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "\033[0;31m" << "A Wrong animal has been killed" << "\033[0;37m" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const& src)
{
	*this = src;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "*WrongAnimal sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(this->_type);
}
