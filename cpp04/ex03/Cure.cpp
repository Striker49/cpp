#include "Cure.hpp"

Cure::Cure(void) : _type("cure")
{
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

Cure::~Cure(void)
{
}