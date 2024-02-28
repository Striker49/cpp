#include "AMateria.hpp"
#include "Ice.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria has been created" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << this->_type << " AMateria has been created" << std::endl;

}

AMateria::AMateria(AMateria const& src)
{
	*this = src;
}

AMateria& AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	// std::cout << " uses a spell on " << target.getName() << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << this->_type << " AMateria has been destroyed" << std::endl;
}