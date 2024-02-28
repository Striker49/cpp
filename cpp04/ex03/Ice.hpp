#pragma once
#include "AMateria.hpp"

class Ice : virtual public AMateria
{
	private:
	public:
		Ice(void);
		Ice(Ice const& src);
		~Ice(void);
		Ice& operator=(Ice const& rhs);
		virtual AMateria* clone( void ) const;

};
