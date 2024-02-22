#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
	ClapTrap(std::string name, int hp, int ep, int ad);
		std::string _name;
		int _hp;
		int _ep;
		int _ad;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const& src );
		~ClapTrap(void);

		ClapTrap&	operator=(ClapTrap const& rhs);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
