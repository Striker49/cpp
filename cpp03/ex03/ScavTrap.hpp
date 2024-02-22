#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		std::string _name;
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const& src );
		~ScavTrap( void );

		ScavTrap const& operator=( ScavTrap const& rhs );
		
		void	virtual attack(const std::string& target);
		void	guardGate();
};
