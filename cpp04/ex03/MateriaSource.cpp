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
		for (int i = 0; i < 4; i++)
			this->_materia[i] = rhs._materia[i];
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
			return;
		}
	}
	delete src;
	std::cout << "Cannot learn more materia..!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			AMateria* tmp = this->_materia[i]->clone();
			// for (int j = 0; j < 100; j++)
			// {
			// 	if (this->_trash[j] == tmp)
			// 		break;
			// 	else if (this->_trash[j] == NULL)
			// 	{
			// 		this->_trash[j] = tmp;
			// 		break;
			// 	}
			// }
			return (tmp);
		}
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
