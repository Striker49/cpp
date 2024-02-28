#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure ability has been created" << std::endl;
}

Cure::Cure(Cure const& src)
{
	*this = src;
}

Cure& Cure::operator=(Cure const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

AMateria* Cure::clone() const
{
	Cure* tmp = new Cure;
	tmp->_type = this->_type;
	return (tmp);
}

Cure::~Cure(void)
{
	std::cout << "Cure ability has been deconstructed" << std::endl;
}