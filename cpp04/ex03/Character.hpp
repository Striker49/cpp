#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

// class ICharacter;

class Character : public ICharacter
{
	protected:
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria*	_trash[100];
	public:
		Character(void);
		Character( std::string name );
		Character( Character const& src );
		~Character( void );
		Character& operator=(Character const& rhs);
		std::string const & getName() const;		
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};
