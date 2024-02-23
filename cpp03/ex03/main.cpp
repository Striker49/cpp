#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap Francoma("Francoma the SmartyPants");
	DiamondTrap Eboyce("Eboyce the Edgelord");

	std::cout << std::endl << std::endl;

	Francoma.whoAmI();
	Eboyce.whoAmI();

	std::cout << std::endl;

	for(int i = 0; i < 5; i++)
	{
		Francoma.attack("Eboyce the Edgelord");
		Eboyce.takeDamage(30);
	}
	Francoma.highFivesGuys();
	// Eboyce.attack("Francoma the SmartyPants");
	// Francoma.DiamondTrap::takeDamage(30);
	Eboyce.beRepaired(10);
	Francoma.beRepaired(10);

	std::cout << std::endl << std::endl;

	return (0);
}