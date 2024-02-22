#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap Francoma("Francoma");
	ClapTrap Eboyce("Eboyce");

	for(int i = 0; i < 9; i++)
	{
		Francoma.attack("Eboyce");
		Eboyce.takeDamage(0);
	}
	Eboyce.attack("Francoma");
	Francoma.takeDamage(0);
	Eboyce.beRepaired(10);
	Francoma.beRepaired(10);
	return (0);
}
