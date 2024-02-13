#include "Contact.hpp"
#include  <string>

Contact::Contact(void)
{
    // std::cout << "C Constructor called" << std::endl;
    return;
}

Contact::~Contact(void)
{
    // std::cout << "C Destructor called" << std::endl;
    return;
}

std::string Contact::getFirstName(void)
{
    return (this->_firstName);
}

std::string Contact::getLastName(void)
{
    return (this->_lastName);
}

std::string Contact::getNickname(void)
{
    return (this->_nickname);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->_darkestSecret);
}

void Contact::setFirstName(void)
{
    while (!std::cin.eof())
    {
        std::getline(std::cin, this->_firstName);
        if (this->_firstName.size() != 0)
            break;
    }
}

void Contact::setLastName(void)
{
    while (!std::cin.eof())
    {
        std::getline(std::cin, this->_lastName);
        if (this->_lastName.size() != 0)
            break;
    }
}

void Contact::setNickname(void)
{
    while (!std::cin.eof())
    {
        std::getline(std::cin, this->_nickname);
        if (this->_nickname.size() != 0)
            break;
    }
}

void Contact::setPhoneNumber(void)
{
    while (!std::cin.eof())
    {
        std::getline(std::cin, this->_phoneNumber);
        if (this->_phoneNumber.size() != 0)
            break;
    }
}

void Contact::setDarkestSecret(void)
{
    while (!std::cin.eof())
    {
        std::getline(std::cin, this->_darkestSecret);
        if (this->_darkestSecret.size() != 0)
            break;
    }
}