#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phoneBook;

    std::string        command;
    std::string str1 = "ADD";
    std::string str2 = "SEARCH";
    std::string str3 = "EXIT";

    std::cout << SET_TERM << std::endl;
    while (!std::cin.eof())
    {
        std::cout << "PhoneBook 1.0" << std::endl << std::endl;
        std::cout << "Use the ADD, SEARCH or EXIT command" << std::endl;
        std::getline(std::cin, command);
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
