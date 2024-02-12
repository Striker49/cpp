#include <iostream>
#include <string>
#include "Harl.hpp"

int main( void )
{
    Harl        Bob;

    Bob.complain("DEBUG");
    Bob.complain("INFO");
    Bob.complain("WARNING");
    Bob.complain("ERROR");
    Bob.complain("ELSE");

}