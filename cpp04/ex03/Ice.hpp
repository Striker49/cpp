#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string _type;
	public:
		Ice(void);
		Ice(Ice const& src);
		~Ice(void);
		Ice& operator=(Ice const& rhs);
};
