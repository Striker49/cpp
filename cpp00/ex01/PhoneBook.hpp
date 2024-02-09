#pragma once
#include "Contact.hpp"
#include <iostream>
# define SET_TERM "\033[2J\033[H"

class PhoneBook {
    int _count;
    int _full;
    Contact    _contact[8];
public:
    PhoneBook(void);
    ~PhoneBook(void);

    void    add(void);
    void    search(void);
    void    exitProgram(void);

};
