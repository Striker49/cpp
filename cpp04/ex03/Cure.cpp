#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure(void) : AMateria("cure")
{
	Character::putInTrash(this);
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
		this->_type = rhs._type;
	}
	return *this;
}

AMateria* Cure::clone() const
{
	Cure* tmp = new Cure;
	tmp->_type = this->_type;
	Character::putInTrash(tmp);
	return (tmp);
}

Cure::~Cure(void)
{
	std::cout << "Cure ability has been deconstructed" << std::endl;
}