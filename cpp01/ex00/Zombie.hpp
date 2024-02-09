#pragma once
#include <iostream>
#include <string>

class Zombie {
public:
    Zombie(void);
    ~Zombie(void);

    void announce( void );
    void randomChump( std::string name );
    void setName( std::string name);

private:
    std::string _name;
};

Zombie* newZombie( std::string name );