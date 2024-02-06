#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
    static int i = 0;

    this->_accountIndex = i;
    std::cout << "[timestamp]" << " index:" << i << ";amount" << initial_deposit << ";created" << std::endl;
    i++;
}

Account::~Account(void)
{
    
}