#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal( void ) : _type("WrongAnimal")
{
	std::cout << "\033[0;31m" << "A Wrong animal has been created" << "\033[0;37m" << std::endl;
}

WrongAAnimal::~WrongAAnimal( void )
{
	std::cout << "\033[0;31m" << "A Wrong AAnimal has been killed" << "\033[0;37m" << std::endl;
}

void WrongAAnimal::makeSound( void ) const
{
	std::cout << "*WrongAAnimal sound*" << std::endl;
}

std::string WrongAAnimal::getType() const
{
	return(this->_type);
}
