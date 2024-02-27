#include "Character.hpp"

Character::Character(void) : _name("")
{
}

Character::Character( std::string name) : _name(name)
{

}

Character::Character( Character const& src )
{
	Character* temp = new Character;
	temp->_name = src._name;
	for (int i = 0; src._inventory[i]; i++)
		temp->_inventory[i] = src._inventory[i];
	*this = *temp;
}

Character& Character::operator=(Character const& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; rhs._inventory[i]; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

std::string const& Character::getName( void ) const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	(void)m;
	// this->inventory[i] = New m;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	// if (this->_inventory.getType().)
	(void)idx;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Character::~Character(void)
{
}