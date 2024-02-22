#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap Francoma("Francoma");
	FragTrap Eboyce("Eboyce");

	for(int i = 0; i < 5; i++)
	{
		Francoma.attack("Eboyce");
		Eboyce.takeDamage(30);
	}
	Francoma.highFivesGuys();
	Eboyce.attack("Francoma");
	Francoma.takeDamage(30);
	Eboyce.beRepaired(10);
	Francoma.beRepaired(10);
	return (0);
}
