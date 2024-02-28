#include "Character.hpp"

Character::Character(void) : _name("")
{
	for (int i = 0; this->_inventory[i]; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default Character has been created" << std::endl;
}

Character::Character( std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << this->_name << " Character has been created" << std::endl;
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
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			delete m;
			std::cout << this->_inventory[i]->getType() << " has been equipped in slot: " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory is already full..!" << std::endl;
}

void Character::unequip(int idx)
{
	if(this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
	else
		std::cout << "There are no Materias to unequip in slot " << idx << "..!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx] == NULL)
		std::cout << this->_name << " doesn't have a spell in slot " << idx << " ..!" << std::endl;
	else
	{
		if (this->_inventory[idx]->getType() == "ice")
			std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
		else if (this->_inventory[idx]->getType() == "cure")
			std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
		else
			std::cout << "* uses a spell on " << target.getName() << " *" << std::endl;
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << this->_name << " Character has been felled" << std::endl;
}