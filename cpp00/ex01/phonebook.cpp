#include "PhoneBook.hpp"
#include <string>
#include <iomanip>
#include <limits>
#include <ios>


PhoneBook::PhoneBook(void)
{
    this->_count = 0;
    this->_full = 0;
    // std::cout << "PB Constructor called" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    // std::cout << "PB Destructor called" << std::endl;
    return;
}

void    PhoneBook::add(void)
{
	std::string null;

    std::cout << SET_TERM << std::endl;
    std::cout << "What's the First Name?" << std::endl;
    _contact[_count].setFirstName();
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Last Name?" << std::endl;
    _contact[_count].setLastName();
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Nickname?" << std::endl;
    _contact[_count].setNickname();
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Phone Number?" << std::endl;
    _contact[_count].setPhoneNumber();
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Darkest Secret?" << std::endl;
    _contact[_count].setDarkestSecret();
    std::cout << SET_TERM << std::endl;

    this->_count++;
    if (this->_count > 7)
    {
        this->_count = 0;
        this->_full = 1;
    }

    std::cout << "\033[1;32m" << "Contact successfully added" << "\033[0;37m" << std::endl << std::endl;
	std::cout << "\033[0;31m" << "Press ENTER to continue..." << "\033[0;37m" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

std::string truncate(std::string str)
{
    std::string str2;

    if (str.length() > 9)
    {
        std::string str2 = str.substr(0, 9);
        std::cout << str2 + ".";
    }
    else
        str2 = str;
    return (str2);
}

void    PhoneBook::search(void)
{
    int size;
    std::string command;


    if (this->_full == 1)
        size = 8;
    else
        size = _count;
    std::cout << std::endl << std::endl <<
    std::setw(10) << std::right << "INDEX" << "|" <<
    std::setw(10) << std::left << "FIRST NAME" << "|" <<
    std::setw(10) << "LAST NAME" << "|" <<
    std::setw(10) << "NICKNAME" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::right << std::setw(10) << i + 1 << "|" <<
        std::setw(10) << std::left << truncate(_contact[i].getFirstName()) << "|" <<
        std::setw(10) << truncate(_contact[i].getLastName()) << "|" <<
        std::setw(10) << truncate(_contact[i].getNickname()) << std::endl;
    }
    if (this->_count == 0 && this->_full == 0)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << std::endl << std::endl;
    std::cout << "Which contact would you like to display?" << std::endl;
	while (!std::cin.eof())
	{
		std::cin >> command;
		if (!isdigit(command[0]) || command.length() > 1)
		{
			std::cout << "\033[0J";
			continue;
		}
		if (stoi(command) >= 1 && stoi(command) < 9 && (stoi(command) <= this->_count || this->_full == 1))
		{
			std::cout << std::endl << std::endl;
			std::cout << "\033[1;34m" << "FIRST NAME:       " << "\033[0;37m" << _contact[stoi(command) - 1].getFirstName() << std::endl << std::endl;
			std::cout << "\033[1;34m" << "LAST NAME:        " << "\033[0;37m"  << _contact[stoi(command) - 1].getLastName() << std::endl << std::endl;
			std::cout << "\033[1;34m" << "NICKNAME:         " << "\033[0;37m"  << _contact[stoi(command) - 1].getNickname() << std::endl << std::endl;
			std::cout << "\033[1;34m" << "PHONE NUMBER:     " << "\033[0;37m"  << _contact[stoi(command) - 1].getPhoneNumber() << std::endl << std::endl;
			std::cout << "\033[1;34m" << "DARKEST SECRET:   " << "\033[0;37m"  << _contact[stoi(command) - 1].getDarkestSecret() << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << "\033[0;31m" << "Press ENTER to continue..." << "\033[0;37m" << std::endl;
			std::getline(std::cin, command);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		std::cout << SET_TERM << std::endl;
			break;
		}
	}
    return;
}

void    PhoneBook::exitProgram(void)
{
    std::cout << "EXITED" << std::endl;
    exit(0);
    return;
}
