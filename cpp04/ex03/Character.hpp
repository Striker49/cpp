#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

// class ICharacter;

class Character : public ICharacter
{
	protected:
		std::string	_name;
		AMateria*	_inventory[4];
		static AMateria*	_trash[100];
		static int	_trashCount;
	public:
		Character(void);
		Character( std::string name );
		Character( Character const& src );
		~Character( void );
		Character& operator=(Character const& rhs);
		std::string const & getName() const;
		static void	putInTrash( AMateria* );
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};
