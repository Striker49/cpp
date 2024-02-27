#include "AMateria.hpp"
#include "Ice.hpp"

AMateria::AMateria(void)
{
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

// AMateria* AMateria::clone() const
// {
// 	AMateria* tmp = new AMateria;
// 	return (*tmp);

// }

void AMateria::use(ICharacter& target)
{
	(void)target;
	// std::cout << " uses a spell on " << target.getName() << std::endl;
}

AMateria::~AMateria(void)
{
}