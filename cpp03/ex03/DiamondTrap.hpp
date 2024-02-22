#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string const& name );
		~DiamondTrap( void );
		DiamondTrap( DiamondTrap const& src );

		DiamondTrap& operator=( DiamondTrap const& rhs );

		using ScavTrap::attack;

		void	whoAmI( void );
};
