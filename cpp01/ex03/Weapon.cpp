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

std::string const& Weapon::getType( void ) const
{
    return (this->_type);
}
