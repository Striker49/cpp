#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice(void) : AMateria("ice")
{
	Character::putInTrash(this);
	std::cout << "Ice ability has been created" << std::endl;
}

Ice::Ice(Ice const& src)
{
	*this = src;
}

Ice& Ice::operator=(Ice const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

AMateria* Ice::clone() const
{
	Ice* tmp = new Ice;
	Character::putInTrash(tmp);
	tmp->_type = this->_type;
	return (tmp);
}

Ice::~Ice(void)
{
	std::cout << "Cure ability has been deconstructed" << std::endl;
}