#pragma once
#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;
    public:
		Weapon( std::string weapon);
		~Weapon( void );
        void            		setType( std::string type);
        std::string&			getType( void );
};
