#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string _name;
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const& src );
		~FragTrap( void );

		FragTrap const& operator=( FragTrap const& rhs );
		
		void	attack(const std::string& target);
		void	highFivesGuys( void );
};
