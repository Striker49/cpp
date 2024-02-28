#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
	public:
		Cure(void);
		Cure(Cure const& src);
		~Cure(void);
		Cure& operator=(Cure const& rhs);
		virtual AMateria* clone( void ) const;
};
