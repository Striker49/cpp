#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria* _materia[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& src);
		~MateriaSource(void);
		MateriaSource& operator=(MateriaSource const& rhs);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};
