#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) :  ClapTrap(name, 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << _hp << std::endl;
	std::cout << ClapTrap::_hp << std::endl;
	std::cout << ScavTrap::_hp << std::endl;
	std::cout << FragTrap::_hp << std::endl;
	std::cout << _ep << std::endl;
	std::cout << _ad << std::endl;
	std::cout << _name << std::endl;
	attack("Someone");

}

DiamondTrap::~DiamondTrap( void )
{
	
}

DiamondTrap::DiamondTrap( DiamondTrap const& src) :  ClapTrap(src._name), ScavTrap(src._name), FragTrap(src._name)
{
	*this = src;
}

DiamondTrap const& DiamondTrap::operator=( DiamondTrap const & rhs)
{
	return (rhs);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << this->_name << std::endl;
}
