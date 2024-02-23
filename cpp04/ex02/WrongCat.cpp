#include "WrongAAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAAnimal(), _type("WrongCat")
{
	std::cout << "\033[0;31m" << "A Wrongcat has been revealed" << "\033[0;37m" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "\033[0;31m" << "A Wrongcat has been reverted to a basic AAnimal" << "\033[0;37m" << std::endl;
}

WrongCat::WrongCat( WrongCat const& src )
{
	*this = src;
}

WrongCat& WrongCat::operator=( WrongCat const& rhs )
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "*Woem* *Woem*" << std::endl;
}

std::string WrongCat::getType() const
{
	return(this->_type);
}
