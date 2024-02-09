#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* _weapon;
        std::string _name;

    public:
        HumanB( std::string name);
        ~HumanB( void );
        void attack( void );
        void setWeapon( Weapon &weapon);
};
