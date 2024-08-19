#include "Data.hpp"

Data::Data(void)
{
}

Data::Data(Data const& src)
{
	*this = src;
}

Data& Data::operator=(Data const& rhs)
{
	if (this != &rhs)
	{
		str = rhs.str;
	}
	return *this;
}

Data::~Data(void)
{
}
