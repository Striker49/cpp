#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
# define SET_TERM "\033[2J\033[H"

class   Contact {
public:
    Contact(void);
    ~Contact(void);

    std::string    firstName;
    std::string    lastName;
    std::string    nickname;
    std::string    phoneNumber;
    std::string    darkestSecret;
};

class PhoneBook {
    int count;
    int full;
public:
    PhoneBook(void);
    ~PhoneBook(void);
    void    add(void);
    void    search(void);
    void    exitProgram(void);

    Contact    _contact[8];
};
