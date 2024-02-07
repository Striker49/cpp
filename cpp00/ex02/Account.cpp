#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
    static int i = 0;

    this->_accountIndex = i;
    _nbAccounts++;
    _totalAmount += initial_deposit;
	Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
    i++;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return(_totalAmount);
}

int Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
	this->_amount += deposit;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (1);
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
		// this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		_totalNbWithdrawals += 1;
		_totalAmount -= withdrawal;
	}
	return (0);
}

void Account::_displayTimestamp( void )
{
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	std::cout << "[" << (now->tm_year + 1900);
	if (now->tm_mon + 1 < 10)
		std::cout << "0" << now->tm_mon + 1;
	else
		std::cout << now->tm_mon + 1;
	if (now->tm_mday < 10)
		std::cout << "0" << now->tm_mday;
	else
		std::cout << now->tm_mday;
	std::cout << "_";
	if (now->tm_hour < 10)
		std::cout << "0" << now->tm_hour;
	else
		std::cout << now->tm_hour;
	if (now->tm_min < 10)
		std::cout << "0" << now->tm_min;
	else
		std::cout << now->tm_min;
	if (now->tm_sec< 10)
		std::cout << "0" << now->tm_sec;
	else
		std::cout << now->tm_sec;
	std::cout << "]";
}