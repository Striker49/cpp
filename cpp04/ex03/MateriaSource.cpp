#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource has been created" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
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

void MateriaSource::learnMateria(AMateria* src)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = src;
			// delete src;
			return;
		}
	}
	std::cout << "Not learned" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; this->_materia[i]; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	std::cout << "The " << type << " materia can't be learned right now..!" << std::endl;
	return (0);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	std::cout << "MateriaSource has been deconstructed" << std::endl;
}
