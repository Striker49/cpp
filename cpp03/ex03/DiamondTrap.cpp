#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :  ClapTrap("", 100, 50, 30), ScavTrap(), FragTrap(), _name("")
{
	this->_hp = FragTrap::_hp;
	std::cout << "DiamondTrap, " << this->_name << " a legendary being, has acended" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const& name ) :  ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap, the legendary being " << this->_name << ", has acended" << std::endl;
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
	std::cout << "\033[1;29m" << "My name is " << this->_name << "\033[1;37m" << std::endl;
	std::cout << "\033[1;29m" << "My ClapTrap name is " << this->ClapTrap::_name << "\033[1;37m" << std::endl;
}
