#include <iostream>
#include <string>
#include "Harl.hpp"

int main(void)
{
    Harl        Bob;

    Bob.complain("debug");
    Bob.complain("info");
    Bob.complain("warning");
    Bob.complain("error");
    Bob.complain("asdasd");
}