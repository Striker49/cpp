#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "Contact.hpp"
# define SET_TERM "\033[2J\033[H"

class PhoneBook {
    int _count;
    int _full;
public:
    PhoneBook(void);
    ~PhoneBook(void);

    void    add(void);
    void    search(void);
    void    exitProgram(void);

    Contact    _contact[8];
};
