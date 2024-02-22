#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap( std::string name );
		~DiamondTrap( void );
		DiamondTrap( DiamondTrap const& src);

		DiamondTrap const& operator=(DiamondTrap const& rhs);

		using FragTrap::attack;

		void	whoAmI( void );
};
