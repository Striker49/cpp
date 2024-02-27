#include "Ice.hpp"

Ice::Ice(void) : _type("ice")
{
}

Ice::Ice(Ice const& src)
{
	*this = src;
}

Ice& Ice::operator=(Ice const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Ice::~Ice(void)
{
}