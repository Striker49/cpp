#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

class   Contact {
public:
    Contact(void);
    ~Contact(void);
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
	std::string getPhoneNumber(void);
    std::string getDarkestSecret(void);
	void setFirstName(void);
    void setLastName(void);
    void setNickname(void);
	void setPhoneNumber(void);
    void setDarkestSecret(void);

private:
    std::string    _firstName;
    std::string    _lastName;
    std::string    _nickname;
    std::string    _phoneNumber;
    std::string    _darkestSecret;
};
