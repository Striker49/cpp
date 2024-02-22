#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 100, 30), _name(name)
{
	std::cout << "FragTrap " << name << " has been created" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << _name << " has been tossed aside" << std::endl;
}

FragTrap::FragTrap( FragTrap const& src) : ClapTrap(src._name, 100, 100, 30), _name(src._name)
{
	*this = src;
}

FragTrap const& FragTrap::operator=( FragTrap const& rhs )
{
	return (rhs);
}


void FragTrap::highFivesGuys( void )
{
	std::cout << "\033[1;37mFragTrap " << this->_name << " wants to high five you!!\033[0;37m" << std::endl;
}

void FragTrap::attack( const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "\033[0;30mFragTrap " << this->_name << " is unable to attack because it has been destroyed..!\033[0;37m" << std::endl;
	}
	else if(this->_ep <= 0)
		std::cout << "\033[0;30mFragTrap " << this->_name << " can't attack " << target << " because he doesn't have enough Energy Points left..!\033[0;37m" << std::endl;
	else
	{		
		std::cout << "\033[1;34mFragTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!\033[0;37m" << std::endl;
		this->_ep--;
	}
}