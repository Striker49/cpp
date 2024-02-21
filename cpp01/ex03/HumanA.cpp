#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _weapon(weapon)
{
    this->_name = name;
    setWeapon(weapon);
}

HumanA::~HumanA(void )
{
    
}

void    HumanA::attack( void )
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon( Weapon &weapon)
{
    weapon.getType();
}