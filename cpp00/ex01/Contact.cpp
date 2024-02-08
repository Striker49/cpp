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
    std::getline(std::cin, this->_firstName);
}

void Contact::setLastName(void)
{
    std::getline(std::cin, this->_lastName);
}

void Contact::setNickname(void)
{
    std::getline(std::cin, this->_nickname);
}

void Contact::setPhoneNumber(void)
{
    std::getline(std::cin, this->_phoneNumber);
}

void Contact::setDarkestSecret(void)
{
    std::getline(std::cin, this->_darkestSecret);
}