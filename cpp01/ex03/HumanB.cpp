#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->_name = name;
}

HumanB::~HumanB(void )
{
    
}

void HumanB::setWeapon( Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack( void )
{
    if (this->_weapon->getType() == "\0")
        std::cout << this->_name << " attacks with their bare hands" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
