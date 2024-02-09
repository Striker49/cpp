#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon& _weapon;
        std::string _name;

    public:
    HumanA( std::string name, Weapon& _weapon);
    ~HumanA( void );
    void attack( void );
    void setWeapon( Weapon weapon);
};
