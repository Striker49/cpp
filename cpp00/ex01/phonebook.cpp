#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->count = 0;
    this->full = 0;
    // std::cout << "PB Constructor called" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    // std::cout << "PB Destructor called" << std::endl;
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

void    PhoneBook::add(void)
{
	std::string null;

    std::cout << SET_TERM << std::endl;
    std::cout << "What's the First Name?" << std::endl;
    std::cin >> this->_contact[this->count].firstName;
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Last Name?" << std::endl;
    std::cin >> this->_contact[this->count].lastName;
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Nickname?" << std::endl;
    std::cin >> this->_contact[this->count].nickname;
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Phone Number?" << std::endl;
    std::cin >> this->_contact[this->count].phoneNumber;
    std::cout << SET_TERM << std::endl;

    std::cout << "What's the Darkest Secret?" << std::endl;
    std::cin >> this->_contact[this->count].darkestSecret;
    std::cout << SET_TERM << std::endl;

    this->count++;
    if (this->count > 7)
    {
        this->count = 0;
        this->full = 1;
    }

    std::cout << "Contact successfully added" << std::endl << std::endl;
	std::cout << "Enter any key and ENTER to continue..." << std::endl;
	std::cin >> null;
	std::cin.ignore();
    return;
}

void    PhoneBook::search(void)
{
    int size;
    std::string command;


    if (this->full == 1)
        size = 8;
    else
        size = count;
    std::cout <<
    std::setw(10) << "INDEX" << "|" <<
    std::setw(10) << "FIRST NAME" << "|" <<
    std::setw(10) << "LAST NAME" << "|" <<
    std::setw(10) << "NICKNAME" << std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|" <<
        std::setw(10) << truncate(_contact[i].firstName) << "|" <<
        std::setw(10) << truncate(_contact[i].lastName) << "|" <<
        std::setw(10) << truncate(_contact[i].nickname) << std::endl;
    }
    if (this->count == 0 && this->full == 0)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << std::endl << std::endl;
    std::cout << "Which contact would you like to display?" << std::endl;
	while (std::cin)
	{
		std::cin >> command;
		if (!isdigit(command[0]) || command.length() > 1)
		{
			std::cout << "\033[0J";
			continue;
		}
		if (stoi(command) >= 1 && stoi(command) < 9 && (stoi(command) <= this->count || this->full == 1))
		{
			std::cout << std::endl << std::endl;
			std::cout << "FIRST NAME:       " << _contact[stoi(command) - 1].firstName << std::endl;
			std::cout << "LAST NAME:        " << _contact[stoi(command) - 1].lastName << std::endl;
			std::cout << "NICKNAME:         " << _contact[stoi(command) - 1].nickname << std::endl;
			std::cout << "PHONE NUMBER:     " << _contact[stoi(command) - 1].phoneNumber << std::endl;
			std::cout << "DARKEST SECRET:   " << _contact[stoi(command) - 1].darkestSecret << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << "Enter any key and ENTER to continue..." << std::endl;
			std::cin >> command;
			std::cin.ignore();
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

int main(void)
{
    PhoneBook   phoneBook;

    std::string        command;
    std::string str1 = "ADD";
    std::string str2 = "SEARCH";
    std::string str3 = "EXIT";

    std::cout << SET_TERM << std::endl;
    while (std::cin)
    {
        std::cout << "PhoneBook 1.0" << std::endl << std::endl;
        std::cout << "Use the ADD, SEARCH or EXIT command" << std::endl;
        std::cin >> command;
        if (command.compare(str1) == 0)
            phoneBook.add();
        else if (command.compare(str2) == 0)
            phoneBook.search();
        else if (command.compare(str3) == 0)
            break;
        std::cout << SET_TERM << std::endl;
    }
    return (0);
}
