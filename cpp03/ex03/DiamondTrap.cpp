#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :  ClapTrap(""), ScavTrap(), FragTrap(), _name("")
{
	this->_hp = FragTrap::_hp;
	this->_ad = FragTrap::_ad;
	this->_ep = ScavTrap::_hp;
	std::cout << "DiamondTrap, " << this->_name << " a legendary being, has acended" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const& name ) :  ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap, the legendary being " << this->_name << ", has ascended" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap, " << this->_name << " a legendary being, has fallen" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const& src) :  ClapTrap(src._name), ScavTrap(src._name), FragTrap(src._name)
{
	*this = src;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return(*this);
}

void	DiamondTrap::whoAmI( void )
{
	if (this->_hp <= 0)
	{
		std::cout << "\033[0;30mDiamondTrap " << this->_name << " is unable to use this ability because it has been destroyed..!\033[0;37m" << std::endl;
	}
	else if(this->_ep <= 0)
		std::cout << "\033[0;30mDiamondTrap " << this->_name << " can't use this ability because it doesn't have enough Energy Points left..!\033[0;37m" << std::endl;
	else
	{
		this->_ep--;
		std::cout << "\033[1;29m" << "My name is " << this->_name << "\033[1;37m" << std::endl;
		std::cout << "\033[1;29m" << "My ClapTrap name is " << this->ClapTrap::_name << "\033[1;37m" << std::endl;
	}
}

void	DiamondTrap::displayStats( void )
{
	std::cout << "These are the stats for " << _name << std::endl;
	std::cout << "HP: " << _hp << std::endl;
	std::cout << "AD: " << _ad << std::endl;
	std::cout << "EP: " << _ep << std::endl;
}
