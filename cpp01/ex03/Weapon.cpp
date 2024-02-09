#include "Weapon.hpp"

Weapon::Weapon( std::string weapon )
{
    this->setType(weapon);
}

Weapon::~Weapon( void )
{

}

void Weapon::setType( std::string type )
{
    this->_type = type;
}

std::string& Weapon::getType( void )
{
    return (this->_type);
}
