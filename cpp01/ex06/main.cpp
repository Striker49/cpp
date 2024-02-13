#include <iostream>
#include <string>
#include "Harl.hpp"

int main( int argc, char **argv)
{
    Harl        Bob;

    if (argc < 2 || argc > 2)
        return(0);

    Bob.complain(argv[1]);
    return (0);
}