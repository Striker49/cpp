#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string _type;
	public:
		Cure(void);
		Cure(Cure const& src);
		~Cure(void);
		Cure& operator=(Cure const& rhs);
};
