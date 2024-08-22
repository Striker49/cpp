#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap Francoma("Francoma the SmartyPants");
	Francoma.displayStats();
	DiamondTrap Eboyce("Eboyce the Edgelord");

	std::cout << std::endl << std::endl;

	Francoma.whoAmI();
	Eboyce.whoAmI();

	std::cout << std::endl;

	for(int i = 0; i < 3; i++)
	{
		Francoma.attack("Eboyce the Edgelord");
		Eboyce.takeDamage(30);
	}
	Francoma.highFivesGuys();
	Eboyce.beRepaired(10);
	Francoma.beRepaired(10);
	Francoma.guardGate();

	std::cout << std::endl << std::endl;
	Francoma.displayStats();

	return (0);
}