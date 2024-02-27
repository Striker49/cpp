#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(void)
{
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	*this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria*)
{
	this->_materia[0] = AMateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria* newMateria;
	newMateria->_type = type;
	return(newMateria);
}

MateriaSource::~MateriaSource(void)
{
}