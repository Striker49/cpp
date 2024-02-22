#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20), _name(name)
{
	std::cout << "ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << _name << " has been disassembled" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const& src) : ClapTrap(src._name)
{
	*this = src;
}

ScavTrap const& ScavTrap::operator=( ScavTrap const& rhs)
{
	return (rhs);
}

void ScavTrap::guardGate( void )
{
	std::cout << "\033[1;37mScavTrap " << this->_name << " is now in Gate keeper mode!!\033[0;37m" << std::endl;
}

void ScavTrap::attack( const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "\033[0;30mScavTrap " << this->_name << " is unable to attack because it has been destroyed..!\033[0;37m" << std::endl;
	}
	else if(this->_ep <= 0)
		std::cout << "\033[0;30mScavTrap " << this->_name << " can't attack " << target << " because he doesn't have enough Energy Points left..!\033[0;37m" << std::endl;
	else
	{		
		std::cout << "\033[1;34mScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!\033[0;37m" << std::endl;
		this->_ep--;
	}
}