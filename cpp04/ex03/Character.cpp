#include "Character.hpp"

AMateria* Character::_trash[100];
int Character::_trashCount = 0;

Character::Character(void) : _name("")
{
	for (int i = 0; i < 4; i++)
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
	// for (int i = 0; this->_trash[i]; i++)
	// 	Character::_trash[i] = src._trash[i];
	*this = *temp;
}

Character& Character::operator=(Character const& rhs)
{
	Character* temp = new Character;
	if (this != &rhs)
	{
		temp->_name = rhs._name;
		for (int i = 0; rhs._inventory[i]; i++)
			temp->_inventory[i] = rhs._inventory[i];
		// for (int i = 0; temp->_trash[i]; i++)
		// 	temp->_trash[i] = rhs._trash[i];
	}
	return (*temp);
}

std::string const& Character::getName( void ) const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid materia type..!" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m->clone();
			std::cout << this->_inventory[i]->getType() << " has been equipped in slot: " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory is already full..!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3)
		std::cout << "The " << idx << "th slot doesn't exist..!" << std::endl;
	if(this->_inventory[idx] != NULL)
	{
		// for (int j = 0; j < 100; j++)
		// {
		// 	if (this->_trash[j] == this->_inventory[idx])
		// 		break;
		// 	else if (this->_trash[j] == NULL)
		// 	{
		// 		this->_trash[j] = this->_inventory[idx];
		// 		break;
		// 	}
		// }
		this->_inventory[idx] = NULL;
	}
	std::cout << "There are no Materias to unequip in slot " << idx << "..!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
		std::cout << "The " << idx << "th slot doesn't exist..!" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << this->_name << " doesn't have a spell in slot " << idx << " ..!" << std::endl;
	else
		this->_inventory[idx]->use(target);
}

void	Character::putInTrash( AMateria* trash)
{
	Character::_trash[Character::_trashCount] = trash;
	Character::_trashCount++;
}

Character::~Character(void)
{
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->_inventory[i] != NULL)
	// 		delete this->_inventory[i];
	// }
	// for (int i = 0; i < Character::_trashCount; i++)
	// {
	// 	if (Character::_trash[i] != NULL)
	// 		delete Character::_trash[i];
	// }
	std::cout << this->_name << " Character has been felled" << std::endl;
}