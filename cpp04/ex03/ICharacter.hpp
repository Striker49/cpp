#pragma once
// #include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter
{
	protected:
	public:
		virtual ~ICharacter( void ) {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
