#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string _name;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const& src );
		~ScavTrap( void );
		
		ScavTrap& operator=( ScavTrap const& rhs );
		
		void	attack(const std::string& target);
		void	guardGate();
};
