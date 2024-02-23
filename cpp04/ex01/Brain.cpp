#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << PINK << "A Brain has been formed..!" << WHITE << std::endl;
}

Brain::Brain(Brain const& src)
{
	*this = src;
}

Brain Brain::operator=(Brain const& rhs)
{
	if (this != &rhs)
	{
		this->_ideas = rhs._ideas;
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << PINK << "A Brain has run its cycle..!" << WHITE << std::endl;
}