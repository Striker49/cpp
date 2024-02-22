#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap Francoma("Francoma");
	DiamondTrap Eboyce("Eboyce");

	for(int i = 0; i < 5; i++)
	{
		Francoma.attack("Eboyce");
		Eboyce.takeDamage(30);
	}
	Francoma.highFivesGuys();
	Eboyce.attack("Francoma");
	Francoma.takeDamage(30);
	Eboyce.beRepaired(5);
	Francoma.beRepaired(5);
	return (0);
}
