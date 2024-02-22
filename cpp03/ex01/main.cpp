#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap Francoma("Francoma");
	ScavTrap Eboyce("Eboyce");

	for(int i = 0; i < 5; i++)
	{
		Francoma.attack("Eboyce");
		Eboyce.takeDamage(20);
	}
	Francoma.guardGate();
	Eboyce.attack("Francoma");
	Francoma.takeDamage(20);
	Eboyce.beRepaired(10);
	Francoma.beRepaired(10);
	return (0);
}
